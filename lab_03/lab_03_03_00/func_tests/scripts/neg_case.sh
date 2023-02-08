#!/bin/bash

neg_file_in=$1
args=$2

./../../app.exe < "$neg_file_in" > output.txt

return=$?

if [ "$return" != 0 ]; then
    exit 0
else
    exit 1
fi

if [ -n "$(USE_VALGRIND)" ]; then
    valgrind --log-file="report.txt" --quiet ./../../app.exe "$args" < "$neg_file_in" > result.txt
    if [ -s report.txt ]; then
        exit 2
    else
        exit 3
    fi
fi



