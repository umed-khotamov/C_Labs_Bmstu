#!/bin/bash

gcc -std=c99 -Wall -Werror main.c --coverage -o0 -o main.exe -lm

cd func_tests/scripts

./func_tests.sh > /dev/null

cd ../..

gcov main.exe

