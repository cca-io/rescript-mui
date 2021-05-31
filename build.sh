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

# Usually the PPX stays compatible and does not need to be rebuilt.
# pushd public/rescript-material-ui-ppx
# esy build
# popd
