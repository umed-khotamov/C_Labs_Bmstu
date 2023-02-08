#ifndef _GET_AND_PUT_H

#define _GET_AND_PUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ARGUMENT_INPUT_ERROR 2
#define NOT_ENOUGH_ARGUMENTS 3
#define NUMBER_INPUT_ERROR 4

#define FILE_OPEN_ERROR 5
#define FILE_WRITE_ERROR 6
#define FILE_SIZE_ERROR 7
#define FILE_READ_ERROR 8

int get_number_by_pos(FILE *file, size_t pos, int *num);
int put_number_by_pos(FILE *file, size_t pos, int num);

#endif
