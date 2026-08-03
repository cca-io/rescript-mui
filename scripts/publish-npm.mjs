import { execSync } from "node:child_process";
import { cpSync, mkdtempSync, readFileSync, rmSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { resolve } from "node:path";

const ref = process.env.GITHUB_REF || "";
const sha = process.env.GITHUB_SHA || "";
const eventPath = process.env.GITHUB_EVENT_PATH || "";
const dryRun = process.env.PUBLISH_DRY_RUN === "true";

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
  {
    path: "packages/rescript-mui-system",
    name: "@rescript-mui/system",
  },
  {
    path: "packages/rescript-mui-x-date-pickers",
    name: "@rescript-mui/x-date-pickers",
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
    } catch {
      console.warn("Failed to read GITHUB_EVENT_PATH payload");
      before = "";
    }
  }

  if (before && before !== EMPTY_SHA) {
    try {
      const output = run(`git diff --name-only ${before} ${sha}`);
      return output ? output.split("\n") : [];
    } catch {
      console.warn(`git diff failed for ${before}..${sha}`);
      return [
        "packages/rescript-mui-material/",
        "packages/rescript-mui-lab/",
        "packages/rescript-mui-system/",
        "packages/rescript-mui-x-date-pickers/",
      ];
    }
  }

  return [
    "packages/rescript-mui-material/",
    "packages/rescript-mui-lab/",
    "packages/rescript-mui-system/",
    "packages/rescript-mui-x-date-pickers/",
  ];
};

const changedIn = (changedPaths, prefixes) =>
  changedPaths.some((file) => prefixes.some((prefix) => file.startsWith(prefix)));

const sharedMaterialReleasePaths = [
  "package.json",
  "yarn.lock",
  ".github/workflows/ci.yml",
  "scripts/publish-npm.mjs",
  "packages/rescript-mui-material/",
];

const sharedLabReleasePaths = [
  "package.json",
  "yarn.lock",
  ".github/workflows/ci.yml",
  "scripts/publish-npm.mjs",
  "packages/rescript-mui-material/",
  "packages/rescript-mui-lab/",
];

const sharedSystemReleasePaths = [
  "package.json",
  "yarn.lock",
  ".github/workflows/ci.yml",
  "scripts/publish-npm.mjs",
  "packages/rescript-mui-material/",
  "packages/rescript-mui-system/",
];

const sharedDatePickersReleasePaths = [
  "package.json",
  "yarn.lock",
  ".github/workflows/ci.yml",
  "scripts/publish-npm.mjs",
  "packages/rescript-mui-material/",
  "packages/rescript-mui-x-date-pickers/",
];

const getNextDevVersion = (pkgName, baseVersion) => {
  if (dryRun) return `${baseVersion}-dev.1`;

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

const getMajorVersion = (version) => {
  const major = Number(version.split(".")[0]);
  if (!Number.isInteger(major) || major < 0) {
    throw new Error(`Cannot determine major version from ${version}`);
  }
  return major;
};

const getReleaseDistTag = (pkgName, version) => {
  const overriddenDistTag = process.env.RELEASE_DIST_TAG;
  if (overriddenDistTag) return overriddenDistTag;

  if (version.includes("-")) return "next";
  if (dryRun) return "latest";

  const releaseMajor = getMajorVersion(version);
  try {
    const latestVersion = run(`npm view ${pkgName} dist-tags.latest`);
    const latestMajor = getMajorVersion(latestVersion);
    if (releaseMajor < latestMajor) return `latest-v${releaseMajor}`;
  } catch {
    console.warn(`Failed to read the latest dist-tag for ${pkgName}`);
  }

  return "latest";
};

const createPublishPlan = ({ path, name }, shouldPublish) => {
  const pkgJson = readPackageJson(path);
  const baseVersion = pkgJson.version;
  let targetVersion = baseVersion;
  let distTag;

  if (!shouldPublish) {
    return { path, name, shouldPublish, baseVersion, targetVersion, distTag };
  }

  if (isTag) {
    if (tagVersion !== baseVersion) {
      throw new Error(
        `Tag ${tagVersion} does not match ${name} version ${baseVersion}`
      );
    }
    distTag = getReleaseDistTag(name, targetVersion);
  } else {
    distTag = "next";
    targetVersion = getNextDevVersion(name, baseVersion);
  }

  return { path, name, shouldPublish, baseVersion, targetVersion, distTag };
};

const getNextVersion = (pkgName) => {
  try {
    return run(`npm view ${pkgName} dist-tags.next`);
  } catch {
    return "";
  }
};

const publishPackage = (plan, materialDevVersion) => {
  const { path, name, shouldPublish, targetVersion, distTag } = plan;
  if (!shouldPublish) {
    console.log(`No changes in ${name}; skipping`);
    return;
  }
  const pkgJson = readPackageJson(path);

  if (!dryRun && fileExistsOnNpm(name, targetVersion)) {
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
  const publishRoot = mkdtempSync(join(tmpdir(), "rescript-mui-publish-"));
  const tempPkgPath = join(publishRoot, path);
  cpSync(path, tempPkgPath, { recursive: true });
  rmSync(join(tempPkgPath, "node_modules"), { recursive: true, force: true });
  pkgJson.version = targetVersion;
  if (
    !isTag &&
    name !== "@rescript-mui/material" &&
    pkgJson.peerDependencies?.["@rescript-mui/material"] &&
    materialDevVersion
  ) {
    pkgJson.peerDependencies["@rescript-mui/material"] = materialDevVersion;
  }
  writePackageJson(tempPkgPath, pkgJson);
  if (dryRun) {
    console.log(
      `Dry run: ${name}@${targetVersion} (${distTag}), material peer ${pkgJson.peerDependencies?.["@rescript-mui/material"] || "n/a"}`
    );
    rmSync(publishRoot, { recursive: true, force: true });
    return;
  }
  try {
    execSync(`npm publish --access public --tag ${distTag} --provenance`, {
      cwd: tempPkgPath,
      stdio: "inherit",
      env: npmEnv,
    });
  } finally {
    rmSync(publishRoot, { recursive: true, force: true });
  }
};

const changedPaths = getChangedPaths();
const changedMaterial =
  isTag ||
  changedIn(changedPaths, sharedMaterialReleasePaths);
const changedLab =
  isTag ||
  changedIn(changedPaths, sharedLabReleasePaths);
const changedSystem =
  isTag ||
  changedIn(changedPaths, sharedSystemReleasePaths);
const changedDatePickers =
  isTag ||
  changedIn(changedPaths, sharedDatePickersReleasePaths);

const publishPlans = [
  createPublishPlan(packages[0], changedMaterial),
  createPublishPlan(packages[1], changedLab),
  createPublishPlan(packages[2], changedSystem),
  createPublishPlan(packages[3], changedDatePickers),
];

const materialDevVersion = isTag
  ? ""
  : publishPlans[0].shouldPublish
    ? publishPlans[0].targetVersion
    : getNextVersion("@rescript-mui/material");

for (const plan of publishPlans) {
  publishPackage(plan, materialDevVersion);
}
