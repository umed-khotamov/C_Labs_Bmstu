#!/bin/bash

neg_file_in=$1
command_valgrind=$2
args=$3

if [ "$command_valgrind" = "--USE_VALGRIND" ]; then
   valgrind --log-file="report.txt" --quiet ./../../main.exe "$args" < "$neg_file_in" > result.txt
fi

./../../main.exe < "$neg_file_in" > output.txt

return=$?

if [ "$return" -eq 1 ]; then
    exit 0
else
    exit 1
fi




