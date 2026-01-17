import { execSync } from "node:child_process";
import { cpSync, mkdtempSync, readFileSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { resolve } from "node:path";

const ref = process.env.GITHUB_REF || "";
const sha = process.env.GITHUB_SHA || "";
const eventPath = process.env.GITHUB_EVENT_PATH || "";
const forcePublish = process.env.FORCE_PUBLISH === "true";
console.log(`GITHUB_REF=${ref}`);
console.log(`GITHUB_SHA=${sha}`);
console.log(`GITHUB_EVENT_PATH=${eventPath}`);
console.log(`FORCE_PUBLISH=${forcePublish}`);
console.log(
  `ACTIONS_ID_TOKEN_REQUEST_URL=${process.env.ACTIONS_ID_TOKEN_REQUEST_URL ? "set" : ""}`
);
console.log(
  `ACTIONS_ID_TOKEN_REQUEST_TOKEN=${process.env.ACTIONS_ID_TOKEN_REQUEST_TOKEN ? "set" : ""}`
);

const isTag = ref.startsWith("refs/tags/v");
const tagVersion = isTag ? ref.replace("refs/tags/v", "") : null;

const packages = [
  {
    path: "packages/rescript-mui-material",
    name: "@rescript-mui/material",
  },
  {
    path: "packages/rescript-mui-lab",
    name: "@rescript-mui/lab",
  },
];

const run = (command, options = {}) =>
  execSync(command, { stdio: "pipe", ...options }).toString().trim();

const fileExistsOnNpm = (pkgName, version) => {
  try {
    execSync(`npm view ${pkgName}@${version} version`, { stdio: "ignore" });
    return true;
  } catch {
    console.warn(`npm view failed for ${pkgName}@${version}`);
    return false;
  }
};

const readPackageJson = (pkgPath) => {
  const raw = readFileSync(join(pkgPath, "package.json"), "utf8");
  return JSON.parse(raw);
};

const writePackageJson = (pkgPath, data) => {
  const raw = `${JSON.stringify(data, null, 2)}\n`;
  writeFileSync(join(pkgPath, "package.json"), raw);
};

const EMPTY_SHA = "0000000000000000000000000000000000000000";

const getChangedPaths = () => {
  if (isTag || !sha) return [];

  let before = "";
  if (eventPath) {
    try {
      const payload = JSON.parse(readFileSync(eventPath, "utf8"));
      before = payload.before || "";
      console.log(`payload.before=${before}`);
    } catch {
      console.warn("Failed to read GITHUB_EVENT_PATH payload");
      before = "";
    }
  }

  if (before && before !== EMPTY_SHA) {
    try {
      const output = run(`git diff --name-only ${before} ${sha}`);
      console.log(`git diff output:\n${output}`);
      return output ? output.split("\n") : [];
    } catch {
      console.warn(`git diff failed for ${before}..${sha}`);
      return [
        "packages/rescript-mui-material/",
        "packages/rescript-mui-lab/",
      ];
    }
  }

  return [
    "packages/rescript-mui-material/",
    "packages/rescript-mui-lab/",
  ];
};

const getNextDevVersion = (pkgName, baseVersion) => {
  let versions = [];
  try {
    const raw = run(`npm view ${pkgName} versions --json`);
    const parsed = JSON.parse(raw);
    versions = Array.isArray(parsed) ? parsed : [parsed];
  } catch {
    console.warn(`Failed to read npm versions for ${pkgName}`);
    versions = [];
  }

  const prefix = `${baseVersion}-dev.`;
  const max = versions
    .filter((v) => v.startsWith(prefix))
    .map((v) => Number(v.slice(prefix.length)))
    .filter((n) => Number.isFinite(n))
    .reduce((a, b) => Math.max(a, b), 0);

  return `${baseVersion}-dev.${max + 1}`;
};

const publishPackage = ({ path, name }, shouldPublish) => {
  if (!shouldPublish) {
    console.log(`No changes in ${name}; skipping`);
    return;
  }

  const pkgJson = readPackageJson(path);
  const baseVersion = pkgJson.version;
  let targetVersion = baseVersion;
  let distTag = "latest";

  if (isTag) {
    if (tagVersion !== baseVersion) {
      throw new Error(
        `Tag ${tagVersion} does not match ${name} version ${baseVersion}`
      );
    }
  } else {
    distTag = "next";
    targetVersion = getNextDevVersion(name, baseVersion);
  }

  if (fileExistsOnNpm(name, targetVersion)) {
    console.log(`${name}@${targetVersion} already exists, skipping`);
    return;
  }

  console.log(`Publishing ${name}@${targetVersion} with dist-tag ${distTag}`);
  const npmEnv = { ...process.env };
  for (const key of Object.keys(npmEnv)) {
    if (key.startsWith("npm_config_workspace") || key.startsWith("npm_config_workspaces")) {
      delete npmEnv[key];
    }
  }
  delete npmEnv.NODE_AUTH_TOKEN;
  delete npmEnv.NPM_CONFIG_USERCONFIG;
  delete npmEnv.npm_config_userconfig;
  console.log(
    `npm_config_workspace=${process.env.npm_config_workspace || ""} npm_config_workspaces=${process.env.npm_config_workspaces || ""}`
  );
  console.log(`NPM_CONFIG_USERCONFIG=${process.env.NPM_CONFIG_USERCONFIG || ""}`);
  const publishRoot = mkdtempSync(join(tmpdir(), "rescript-mui-publish-"));
  const tempPkgPath = join(publishRoot, path);
  cpSync(path, tempPkgPath, { recursive: true });
  rmSync(join(tempPkgPath, "node_modules"), { recursive: true, force: true });
  pkgJson.version = targetVersion;
  writePackageJson(tempPkgPath, pkgJson);
  execSync(`npm publish --access public --tag ${distTag} --provenance`, {
    cwd: tempPkgPath,
    stdio: "inherit",
    env: npmEnv,
  });
};

const changedPaths = getChangedPaths();
const changedMaterial =
  forcePublish ||
  isTag ||
  changedPaths.some((file) =>
    file.startsWith("packages/rescript-mui-material/")
  );
const changedLab =
  forcePublish ||
  isTag ||
  changedPaths.some((file) => file.startsWith("packages/rescript-mui-lab/"));
console.log(`changedPaths=${changedPaths.length}`);
console.log(`changedMaterial=${changedMaterial}`);
console.log(`changedLab=${changedLab}`);

publishPackage(packages[0], changedMaterial);
publishPackage(packages[1], changedLab);
