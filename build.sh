#!/bin/bash
pwd=$(pwd)

git pull
rush update
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

cd public/bs-material-ui-ppx
yarn build

cd $pwd