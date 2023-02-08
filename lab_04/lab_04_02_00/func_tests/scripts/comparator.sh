#!/bin/bash 

file_input=$1
file_output=$2

grep -zoP 'Result:\n\K(.|\n)*' "$file_input" > result1.txt
grep -zoP 'Result:\n\K(.|\n)*' "$file_output" > result2.txt
 
if [ -z "$(diff -q result1.txt result2.txt)" ]; then
    echo 0
else
    echo 1
fi
