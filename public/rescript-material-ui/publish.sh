#!/bin/bash
rm src/*.bs.js
cp ./../../README.md ./README.md
yarn publish --access public
rm ./README.md
