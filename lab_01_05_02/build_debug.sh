#!/bin/bash


gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g3 -c main.c
gcc -o main.exe main.o -lm
