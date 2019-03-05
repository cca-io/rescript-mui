#!/bin/bash
mv ./bsconfig.json ./bsc.json; mv ./bsconfig-npm.json ./bsconfig.json
yarn publish
mv ./bsconfig.json ./bsconfig-npm.json; mv ./bsc.json ./bsconfig.json