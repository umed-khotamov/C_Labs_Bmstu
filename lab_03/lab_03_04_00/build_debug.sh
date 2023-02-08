#!/bin/bash


gcc -std=c99 -Wall -Werror -Wvla -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g3 -c main.c
gcc -o app.exe main.o -lm
