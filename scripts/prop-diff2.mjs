// Compares v9 .d.ts own-props of each material component against its .res binding,
// resolving ReScript record spreads (...Module.field) transitively so inherited
// props don't show up as false "missing".
import fs from "node:fs";
import path from "node:path";

const MUI = "node_modules/@mui/material";
const PKG = "packages/rescript-mui-material/src";
const SRC = path.join(PKG, "components");

const fileByModule = {};
for (const dir of ["components", "types"]) {
  for (const f of fs.readdirSync(path.join(PKG, dir))) {
    if (f.endsWith(".res")) fileByModule[f.replace(/\.res$/, "")] = path.join(PKG, dir, f);
  }
}

const textCache = {};
const readMod = (mod) => {
  if (!(mod in textCache)) {
    const f = fileByModule[mod];
    textCache[mod] = f ? fs.readFileSync(f, "utf8") : null;
  }
  return textCache[mod];
};

function recordBody(src, name) {
  const re = new RegExp(`type ${name}(<[^>]*>)?\\s*=\\s*\\{`, "m");
  const m = re.exec(src);
  if (!m) return null;
  let i = m.index + m[0].length;
  let depth = 1;
  const start = i;
  for (; i < src.length && depth > 0; i++) {
    if (src[i] === "{") depth++;
    else if (src[i] === "}") depth--;
  }
  return src.slice(start, i - 1);
}

const tokCache = {};
function tokensOf(mod, recName, seen = new Set()) {
  const key = `${mod}.${recName}`;
  if (seen.has(key)) return new Set();
  seen.add(key);
  if (tokCache[key]) return tokCache[key];
  const src = readMod(mod);
  const out = new Set();
  if (!src) return out;
  const body = recordBody(src, recName);
  if (!body) return out;
  for (const raw of body.split("\n")) {
    const line = raw.trim();
    let mm;
    if ((mm = line.match(/^\.\.\.([A-Z][A-Za-z0-9_]*)\.([a-zA-Z0-9_]+)/))) {
      for (const t of tokensOf(mm[1], mm[2], seen)) out.add(t);
    } else if ((mm = line.match(/^\.\.\.([a-z][A-Za-z0-9_]*)/))) {
      for (const t of tokensOf(mod, mm[1], seen)) out.add(t);
    } else if ((mm = line.match(/@as\("([^"]+)"\)/))) {
      out.add(mm[1]);
      const f = line.match(/@as\("[^"]+"\)\s*([a-zA-Z_][a-zA-Z0-9_]*)\??:/);
      if (f) out.add(f[1]);
    } else if ((mm = line.match(/^([a-zA-Z_][a-zA-Z0-9_]*)\??:/))) {
      out.add(mm[1]);
    }
  }
  tokCache[key] = out;
  return out;
}

function resProps(comp) {
  const src = readMod(comp);
  if (!src) return null;
  const out = new Set();
  for (const rec of ["props", "publicProps", "publicPropsWithOnClick"]) {
    for (const t of tokensOf(comp, rec)) out.add(t);
  }
  // handle `type props = someLocalRecord<...>` alias
  const alias = src.match(/type props(<[^>]*>)?\s*=\s*([a-z][A-Za-z0-9_]*)/);
  if (alias) for (const t of tokensOf(comp, alias[2])) out.add(t);
  return out;
}

function dtsOwnProps(comp) {
  const f = path.join(MUI, comp, `${comp}.d.ts`);
  if (!fs.existsSync(f)) return null;
  const src = fs.readFileSync(f, "utf8");
  const props = new Set();
  const re = /export interface (\w+)([^{]*)\{([\s\S]*?)\n\}/g;
  let m;
  const wanted = new Set([`${comp}Props`, `${comp}OwnProps`, `${comp}BaseProps`]);
  while ((m = re.exec(src))) {
    const name = m[1];
    if (!wanted.has(name)) continue;
    for (const line of m[3].split("\n")) {
      const mm = line.match(/^\s{2}([a-zA-Z_][a-zA-Z0-9_]*)\??:/);
      if (mm) props.add(mm[1]);
    }
  }
  return props;
}

const IGNORE = new Set(["defaultComponent", "props", "unstable_level"]);

const comps = fs.readdirSync(SRC).filter((f) => f.endsWith(".res")).map((f) => f.replace(/\.res$/, ""));
for (const comp of comps) {
  const own = dtsOwnProps(comp);
  const have = resProps(comp);
  if (!own || !have || own.size === 0) continue;
  const missing = [...own].filter((p) => !have.has(p) && !IGNORE.has(p));
  if (missing.length) console.log(`${comp}: ${missing.join(" ")}`);
}
