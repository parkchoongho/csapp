#!/bin/bash

python3 a.py 10 &
pid2=$!
python3 a.py 5 &
pid=$!
echo "running python3 a.py 1 ## pid: $pid $pid2"
wait $pid $pid2

python3 a.py 3 &
pid1=$!
echo "running python3 a.py 3 ## pid: $pid1"
wait $pid1