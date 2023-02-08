#!/bin/bash 

file_input=$1
file_output=$2

grep -oE "[+-]?[0-9]+([.][0-9]+)?" "$file_input" > result1.txt
grep -oE "[+-]?[0-9]+([.][0-9]+)?" "$file_output" > result2.txt

if [ -z "$(diff -q result1.txt result2.txt)" ]; then
    echo 0
else
    echo 1
fi

