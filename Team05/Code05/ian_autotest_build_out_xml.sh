#!/usr/bin/env bash

# Taken from https://nus-cs3203.github.io/course-website/contents/tools/autotester-testing.html

echo [ianscript] running autotester
cd tests
../cmake-build-debug/src/autotester/autotester Sample_source.txt Sample_queries.txt out.xml

