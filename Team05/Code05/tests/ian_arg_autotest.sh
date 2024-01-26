#!/usr/bin/env bash
# Takes in the source, queries and out as parameters
# Taken from https://nus-cs3203.github.io/course-website/contents/tools/autotester-testing.html

echo [ianscript] running autotester from test dir
../build/src/autotester/autotester $1 $2 $3

