#!/bin/bash

file_in=$1
file_out=$2
args=$3

./../../app.exe "$args" < "$file_in" > output_check.txt

file_in=output_check.txt

if [ "$(./comparator.sh "$file_in" "$file_out")" -eq 0 ]; then
    exit 0
else
    exit 1
fi

if [ -n "$(USE_VALGRIND)" ]; then
    valgrind --log-file="report.txt" --quiet ./../../app.exe "$args" < "$file_in" > result.txt
    if [ -s report.txt ]; then
        exit 2
    else
        exit 3
    fi
fi


