#!/bin/bash
./node_modules/.bin/ts-node --project ./tsconfig.json --files ./src/index.ts;
./node_modules/.bin/bsrefmt --in-place ./../../output/reason/*.re;
./node_modules/.bin/bsb -make-world;
# rm ./../../output/reason/*.bs.js;
rm ./../../public/bs-material-ui/src/*;
mv ./../../output/reason/*.re ./../../public/bs-material-ui/src;
mv ./../../output/reason/*.bs.js ./../../public/bs-material-ui/src;