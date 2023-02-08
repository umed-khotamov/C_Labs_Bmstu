#include <stdlib.h>
#include <string.h>

#include "errs_defs.h"
#include "funcs.h"

int get_command(const int argc, const char *argv[], int *command)
{
    if (argc == MAX_ARGS && (strcmp(argv[MAX_ARGS - 1], "f") == 0))
        *command = FILTER_SORT;
    else if (argc == MIN_ARGS)
        *command = SORT;
	
    return *command ? EXIT_SUCCESS : ERR_ARGS;
}

size_t init_new_array(int *start, int *end, int **new_array_start, int **new_array_end)
{
    size_t size = 0;

    for (int *i = start; i < end && *i >= 0; i++)
        size++;

    int *new_array = malloc(size * sizeof(int));

    *new_array_start = new_array;
    *new_array_end = new_array + size;

    return size; 
}
