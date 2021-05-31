#!/bin/bash
rm src/*.bs.js
mv ./bsconfig.json ./bsc.json; mv ./bsconfig-npm.json ./bsconfig.json
cp ./../../README.md ./README.md
yarn publish --access public
mv ./bsconfig.json ./bsconfig-npm.json; mv ./bsc.json ./bsconfig.json
rm ./README.md
