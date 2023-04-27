#!/bin/bash

pushd public/rescript-material-ui
yarn build
popd

pushd public/rescript-material-ui-lab
yarn build
popd

pushd examples
yarn build
popd
