#!/bin/bash
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/index.ts;
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/lab.ts;
./node_modules/.bin/bsrefmt --in-place ./../../output/reason/core/*.res;
./node_modules/.bin/bsrefmt --in-place ./../../output/reason/lab/*.res;
./node_modules/.bin/bsb -make-world;

# Core
rm ./../../output/reason/core/*.js;
rm ./../../public/bs-material-ui/src/*;
mv ./../../output/reason/core/*.res ./../../public/bs-material-ui/src;

# Lab
rm ./../../output/reason/lab/*.js;
rm ./../../public/bs-material-ui-lab/src/*;
mv ./../../output/reason/lab/*.res ./../../public/bs-material-ui-lab/src;