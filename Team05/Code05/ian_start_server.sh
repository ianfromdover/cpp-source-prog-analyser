#!/usr/bin/env bash
cd tests
python -m http.server 8000 &
sleep 0.5
open -a Safari http://localhost:8000/out.xml
