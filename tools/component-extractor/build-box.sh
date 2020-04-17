#!/bin/bash
pwd=$(pwd)

var=$(comby -templates ./comby -f index.d.ts -d system -matcher .js -newline-separated -stdout)
var=$(printf "$var" | sort | uniq)
var=${var%?}
comby "\"props\": {}" "$var" box-template.json -matcher .json -stdout | uniq > "${pwd}/../../output/json/box.json"