#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wvla -Wpedantic -Wfloat-equal -Wfloat-conversion -c main.c
gcc -o app.exe main.o -lm

