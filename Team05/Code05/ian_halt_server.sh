#!/usr/bin/env bash

pid=$(pgrep python)
echo $pid
kill -9 $pid
