#!/bin/bash
pwd=$(pwd)

git pull
rm -rf output

cd tools/json-schema-parser
yarn
yarn build

cd $pwd

cd tools/component-extractor
yarn
yarn build

cd $pwd

cd tools/binding-generator
yarn
yarn build

cd $pwd

cd public/bs-material-ui-ppx
yarn
yarn build

cd $pwd