#!/bin/bash

file_in=$1
file_out=$2
command_valgrind=$3
args=$4

if [ "$command_valgrind" = "--USE_VALGRIND" ]; then
    valgrind --log-file="report.txt" --quiet ./../../main.exe "$args" < "$file_in" > result.txt
fi

if [ "$(./comparator.sh "$file_in" "$file_out")" -eq 0 ]; then
    exit 0
else
    exit 1
fi
