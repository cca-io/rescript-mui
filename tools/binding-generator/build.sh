#!/bin/bash
./node_modules/.bin/ts-node --project tsconfig.json --files ./src/index.ts
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/lab.ts
./node_modules/.bin/rescript format ./../../output/rescript/core/*.res
./node_modules/.bin/rescript format ./../../output/rescript/lab/*.res

# Core
rm ../../public/rescript-material-ui/src/*
mv ../../output/rescript/core/*.res ../../public/rescript-material-ui/src
mv ../../output/rescript/core/*.resi ../../public/rescript-material-ui/src

# Lab
rm ../../public/rescript-material-ui-lab/src/*
mv ../../output/rescript/lab/*.res ../../public/rescript-material-ui-lab/src