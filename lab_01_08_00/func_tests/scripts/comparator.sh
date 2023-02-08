#!/bin/bash 

file_input=$1
file_output=$2

../../main.exe < "$file_input" > output_check.txt

grep -oE "Result: .*" output_check.txt > result1.txt
grep -oE "Result: .*" "$file_output" > result2.txt

if [ -z "$(diff -q result1.txt result2.txt)" ]; then
    echo 0
else
    echo 1
fi

