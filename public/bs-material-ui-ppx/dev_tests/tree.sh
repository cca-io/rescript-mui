#!/bin/sh
ocamlc -pp "./../node_modules/.bin/bsrefmt --print binary" -dparsetree -impl "$1"