#!/bin/bash
pwd=$(pwd)

git pull
rm -rf output

cd tools/json-schema-parser
yarn build

cd $pwd

cd tools/component-extractor
yarn build

cd $pwd

cd tools/binding-generator
yarn build

cd $pwd

# Usually the PPX stays compatible and does not need to be rebuilt.
# cd public/bs-material-ui-ppx
# esy build

cd $pwd