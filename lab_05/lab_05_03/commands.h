#ifndef _COMMANDS_H

#define _COMMANDS_H

#include "get_and_put.h"
#include "check_args.h"

int file_size(FILE *file, size_t *size);
int write_random(char *string, char **argv);
int print_file(char **argv);
int file_sort(char **argv);

#endif
