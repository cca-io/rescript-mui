#!/bin/bash
rm src/*.bs.js
mv ./bsconfig.json ./bsc.json; mv ./bsconfig-npm.json ./bsconfig.json
yarn publish --access public --tag zero
mv ./bsconfig.json ./bsconfig-npm.json; mv ./bsc.json ./bsconfig.json
