#!/bin/bash
pwd=$(pwd)

# https://gist.github.com/lukechilds/a83e1d7127b78fef38c2914c4ececc3c
get_releases() {
  curl --silent "https://api.github.com/repos/$1/releases" |
  grep '"tag_name":' |
  sed -E 's/.*"([^"]+)".*/\1/'
}

# Update git repo
if [ ! -d "~/.mui-clone" ]; then
  git clone https://github.com/mui-org/material-ui ~/.mui-clone
fi
cd ~/.mui-clone
git checkout master
git reset --hard
git pull
releases=$(get_releases mui-org/material-ui)
select TAGNAME in $releases;
do
  case $TAGNAME in
        *)
          break
          ;;
  esac
done
git checkout $TAGNAME
cd $pwd

# Copy source files
rm -rf ./core
cp -R ~/.mui-clone/packages/material-ui/src ./core
rm -rf ./lab
cp -R ~/.mui-clone/packages/material-ui-lab/src ./lab
rm -rf ./styles
cp -R ~/.mui-clone/packages/material-ui-styles/src ./styles
rm -rf ./utils
cp -R ~/.mui-clone/packages/material-ui-utils/src ./utils
rm -rf ./system
cp -R ~/.mui-clone/packages/material-ui-system/src ./system

# Ensure output folder
if [ ! -d "./../../output" ]; then
  mkdir ./../../output
fi

# Extract components

cd ~/.mui-clone
mv node_modules_tmp node_modules
yarn
cd $pwd
rm -rf ./../../output/json
yarn babel-node ./src/extract.js --src=core
yarn babel-node ./src/extract.js --src=lab
cd ~/.mui-clone
mv node_modules node_modules_tmp
cd $pwd

# Extract json schemas
cd ~/.mui-clone/packages/material-ui;
"${pwd}/node_modules/.bin/typescript-json-schema" ./tsconfig.json Theme --topRef --ignoreErrors --excludePrivate --required -o "${pwd}/../../output/json/core/theme.json"
echo "Extracted theme.json"
"${pwd}/node_modules/.bin/typescript-json-schema" ./tsconfig.json ThemeOptions --topRef --ignoreErrors --excludePrivate --required -o "${pwd}/../../output/json/core/theme-options.json"
echo "Extracted theme-options.json"
cd $pwd