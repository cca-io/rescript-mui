#!/bin/bash

pushd tools/json-schema-parser
yarn build
popd

pushd tools/component-extractor
yarn build
popd

pushd tools/binding-generator
yarn build
popd

pushd public/rescript-material-ui
yarn build
popd

pushd public/rescript-material-ui-lab
yarn build
popd

pushd examples
yarn build
popd
