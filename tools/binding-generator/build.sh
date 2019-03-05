#!/bin/bash
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/index.ts;
./node_modules/.bin/bsrefmt --in-place ./../../output/reason/*.re;
bsb -make-world;
rm -rf ./../../output/reason/*.bs.js;