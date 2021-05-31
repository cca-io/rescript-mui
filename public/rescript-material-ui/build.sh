#!/bin/bash
rm src/*
cp ../../output/reason/*.re src
yarn bs:build
rm src/*.bs.js