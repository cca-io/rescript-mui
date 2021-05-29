#!/bin/bash
pwd=$(pwd)

MUI_VERSION_TAG=v4.11.4
OUTPUT_FOLDER=${pwd}/../../output

rm -rf ~/.mui-clone
git clone --depth 1 --branch $MUI_VERSION_TAG https://github.com/mui-org/material-ui ~/.mui-clone

# Copy source files
rm -rf ./core
cp -R ~/.mui-clone/packages/material-ui/src ./core
rm -rf ./lab
cp -R ~/.mui-clone/packages/material-ui-lab/src ./lab
rm -rf ./styles
cp -R ~/.mui-clone/packages/material-ui-styles/src ./styles
rm -rf ./utils
cp -R ~/.mui-clone/packages/material-ui-utils/src ./utils
cp -R ~/.mui-clone/packages/material-ui-utils/macros ./utils/macros
cp -R ~/.mui-clone/packages/material-ui-utils/src ./utils/src
rm -rf ./node_modules/@material-ui
mkdir ./node_modules/@material-ui
mkdir ./node_modules/@material-ui/utils
cp -R ~/.mui-clone/packages/material-ui-utils/macros ./node_modules/@material-ui/utils
rm -rf ./system
cp -R ~/.mui-clone/packages/material-ui-system/src ./system

# Extract components
pushd ~/.mui-clone
yarn
popd

rm -rf $OUTPUT_FOLDER
mkdir $OUTPUT_FOLDER
npx babel-node ./src/extract.js --src=core
npx babel-node ./src/extract.js --src=lab

# This is necessary, otherwise we get "Maximum call stack size exceeded"
rm -rf ~/.mui-clone/node_modules

# Extract json schemas
pushd ~/.mui-clone/packages/material-ui;
"${pwd}/node_modules/.bin/typescript-json-schema" ./tsconfig.json Theme --topRef --ignoreErrors --excludePrivate --required -o "$OUTPUT_FOLDER/json/core/theme.json"
echo "Extracted theme.json"
"${pwd}/node_modules/.bin/typescript-json-schema" ./tsconfig.json ThemeOptions --topRef --ignoreErrors --excludePrivate --required -o "$OUTPUT_FOLDER/json/core/theme-options.json"
echo "Extracted theme-options.json"
popd
