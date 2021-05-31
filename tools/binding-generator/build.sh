#!/bin/bash
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/index.ts;
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/lab.ts;
./node_modules/.bin/rescript format ./../../output/reason/core/*.res;
./node_modules/.bin/rescript format ./../../output/reason/lab/*.res;
./node_modules/.bin/rescript;

# Core
rm ./../../output/reason/core/*.js;
rm ./../../public/rescript-material-ui/src/*;
mv ./../../output/reason/core/*.res ./../../public/rescript-material-ui/src;

# Lab
rm ./../../output/reason/lab/*.js;
rm ./../../public/rescript-material-ui-lab/src/*;
mv ./../../output/reason/lab/*.res ./../../public/rescript-material-ui-lab/src;