#!/bin/bash
pwd=$(pwd)

MUI_VERSION_TAG=v5.11.2
OUTPUT_FOLDER=${pwd}/../../output

# if changing the MUI_VERSION_TAG, delete the repo directory and clone again
# rm -rf ~/.mui-clone
if [ ! -d ~/.mui-clone ]; then
  git clone --depth 1 --branch $MUI_VERSION_TAG https://github.com/mui/material-ui ~/.mui-clone
else
  pushd ~/.mui-clone
  git checkout $MUI_VERSION_TAG
  popd
fi

# Build all the MUI packages we need for nodejs
pushd ~/.mui-clone
yarn

pushd ./packages/mui-base
yarn build:node
popd

pushd ./packages/mui-material
yarn build:node
popd

pushd ./packages/mui-styles
yarn build:node
popd

pushd ./packages/mui-styled-engine
yarn build:node
popd

pushd ./packages/mui-private-theming
yarn build:node
popd

pushd ./packages/mui-system
yarn build:node
popd

pushd ./packages/mui-utils
yarn build:node
popd

pushd ./packages/mui-lab
yarn build:node
popd

popd

# Copy source files
rm -rf ./core
cp -R ~/.mui-clone/packages/mui-material/build/node ./core

rm -rf ./material
cp -R ~/.mui-clone/packages/mui-material/src ./material

cp -R ./core/generateUtilityClass ./material/
cp -R ./core/generateUtilityClasses ./material/
cp -R ./core/className ./material/
cp -R ./core/Popper ./material/
cp -R ./core/FormControl ./material/
cp -R ./core/transitions ./material/
cp -R ./core/utils ./material/
cp -R ./core/styles ./material/
cp ./core/ButtonGroup/ButtonGroupContext.js ./material/ButtonGroup
cp ./core/Dialog/DialogContext.js ./material/Dialog
cp ./core/Link/getTextDecoration.js ./material/Link
cp ./core/RadioGroup/useRadioGroup.js ./material/RadioGroup
cp ./core/RadioGroup/RadioGroupContext.js ./material/RadioGroup
cp ./core/useMediaQuery/useMediaQuery.js ./material/useMediaQuery
cp ./core/Stepper/StepperContext.js ./material/Stepper
cp ./core/Step/StepContext.js ./material/Step

## Copy over missing JS files (Babel ignores the .ts files here)
for dir in `find ./core -name \*Classes.js`; do
  removePrefix=${dir#"./core"}
  removeSuffix=${removePrefix%/*}
  target="./material"$removeSuffix"/"
  cp -R $dir $target
done

rm -rf ./lab
cp -R ~/.mui-clone/packages/mui-lab/src ./lab

rm -rf ./dist-lab
cp -R ~/.mui-clone/packages/mui-lab/build/node ./dist-lab
cp ./dist-lab/Timeline/TimelineContext.js ./lab/Timeline

## Copy over missing JS files
for dir in `find ./dist-lab -name \*Classes.js`; do
  removePrefix=${dir#"./dist-lab"}
  removeSuffix=${removePrefix%/*}
  target="./lab"$removeSuffix"/"
  cp -R $dir $target
done


rm -rf ./base
cp -R ~/.mui-clone/packages/mui-base/build/node ./base
rm -rf ./styles
cp -R ~/.mui-clone/packages/mui-styles/build/node ./styles
rm -rf ./styled-engine
cp -R ~/.mui-clone/packages/mui-styled-engine/build/node ./styled-engine
rm -rf ./private-theming
cp -R ~/.mui-clone/packages/mui-private-theming/build/node ./private-theming
rm -rf ./system
cp -R ~/.mui-clone/packages/mui-system/build ./system
rm -rf ./utils
cp -R ~/.mui-clone/packages/mui-utils/build ./utils/
cp -R ~/.mui-clone/packages/mui-utils/macros ./utils/macros

# Extract components
rm -rf $OUTPUT_FOLDER
mkdir $OUTPUT_FOLDER
npx babel-node ./src/extract.js --src=material
npx babel-node ./src/extract.js --src=lab

# This is necessary, otherwise we get "Maximum call stack size exceeded"
rm -rf ~/.mui-clone/node_modules

# Extract json schemas
pushd ~/.mui-clone/packages/mui-material;
"${pwd}/node_modules/.bin/typescript-json-schema" ./tsconfig.json Theme --topRef --ignoreErrors --excludePrivate --required -o "$OUTPUT_FOLDER/json/material/theme.json"
echo "Extracted theme.json"
"${pwd}/node_modules/.bin/typescript-json-schema" ./tsconfig.json ThemeOptions --topRef --ignoreErrors --excludePrivate --required -o "$OUTPUT_FOLDER/json/material/theme-options.json"
echo "Extracted theme-options.json"
popd
