#!/bin/sh
# ocamlc -pp "./node_modules/.bin/bsrefmt --print binary" -dparsetree -impl "$1"
./node_modules/.bin/bsc -dsource -dparsetree "$1"
