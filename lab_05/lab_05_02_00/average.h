#ifndef _AVERAGE_H

#define _AVERAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILE_OPEN_ERROR 101
#define FILE_INPUT_ERROR 102

#define NO_FILE 100
#define NO_DATA 103

int find_average(FILE *file, double *average);
double find_close_to_average(FILE *file, double average);

#endif
