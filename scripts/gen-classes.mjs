// One-off migration helper: regenerate ReScript `type classes = {...}` blocks
// from the actual @mui/material v9 *Classes.d.ts files.
// Usage: node scripts/gen-classes.mjs [--apply] [Component ...]
import fs from "node:fs";
import path from "node:path";

const ROOT = path.resolve(import.meta.dirname, "..");
const COMPONENTS_DIR = path.join(
  ROOT,
  "packages/rescript-mui-material/src/components"
);
const MUI = path.join(ROOT, "node_modules/@mui/material");

const apply = process.argv.includes("--apply");
const only = process.argv.slice(2).filter((a) => !a.startsWith("--"));

function classFileFor(comp) {
  const camel = comp[0].toLowerCase() + comp.slice(1);
  return path.join(MUI, comp, `${camel}Classes.d.ts`);
}

// Parse the `export interface XClasses { ... }` body into [{doc, key}]
function parseClasses(dts) {
  const m = dts.match(/export interface \w+Classes \{([\s\S]*?)\n\}/);
  if (!m) return null;
  const body = m[1];
  const lines = body.split("\n");
  const entries = [];
  let pending = [];
  let inBlock = false;
  for (const raw of lines) {
    const line = raw.replace(/\s+$/, "");
    if (!line.trim()) continue;
    if (inBlock) {
      pending.push(line);
      if (line.includes("*/")) inBlock = false;
      continue;
    }
    const trimmed = line.trim();
    if (trimmed.startsWith("/**")) {
      pending.push(line);
      if (!line.includes("*/")) inBlock = true;
      continue;
    }
    const f = trimmed.match(/^([A-Za-z0-9_]+)\??:\s*string;/);
    if (f) {
      entries.push({ doc: pending, key: f[1] });
      pending = [];
    } else {
      pending = [];
    }
  }
  return entries;
}

function buildBlock(entries) {
  let out = "type classes = {\n";
  for (const { doc, key } of entries) {
    for (const d of doc) {
      // normalize indentation to 2 spaces
      out += "  " + d.trim() + "\n";
    }
    out += `  ${key}?: string,\n`;
  }
  out += "}";
  return out;
}

function replaceBlock(src, newBlock) {
  const start = src.indexOf("type classes = {");
  if (start === -1) return null;
  // find closing "\n}" (a line that is exactly "}")
  const rest = src.slice(start);
  const endRel = rest.search(/\n\}/);
  if (endRel === -1) return null;
  const end = start + endRel + 2; // include "\n}"
  return src.slice(0, start) + newBlock + src.slice(end);
}

const files = fs
  .readdirSync(COMPONENTS_DIR)
  .filter((f) => f.endsWith(".res"))
  .map((f) => f.replace(/\.res$/, ""));

let changed = 0;
for (const comp of files) {
  if (only.length && !only.includes(comp)) continue;
  const cf = classFileFor(comp);
  if (!fs.existsSync(cf)) continue;
  const resPath = path.join(COMPONENTS_DIR, `${comp}.res`);
  const src = fs.readFileSync(resPath, "utf8");
  if (!src.includes("type classes = {")) continue;
  const entries = parseClasses(fs.readFileSync(cf, "utf8"));
  if (!entries || entries.length === 0) continue;
  const newBlock = buildBlock(entries);
  const next = replaceBlock(src, newBlock);
  if (next == null) {
    console.error(`!! could not locate classes block in ${comp}.res`);
    continue;
  }
  if (next === src) continue;
  changed++;
  if (apply) {
    fs.writeFileSync(resPath, next);
    console.log(`updated ${comp}.res`);
  } else {
    console.log(`\n===== ${comp} (dry-run) =====`);
    console.log(newBlock);
  }
}
console.log(`\n${apply ? "applied" : "would change"}: ${changed} files`);
