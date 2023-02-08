#include <stdlib.h>
#include <string.h>

#include "errs_defs.h"

int get_command(const int argc, const char *argv[], int *command)
{
    if (argc == MAX_ARGS && (strcmp(argv[MAX_ARGS - 1], "f") == 0))
        *command = FILTER_SORT;
    else if (argc == MIN_ARGS)
        *command = SORT;
	
    return *command ? EXIT_SUCCESS : ERR_ARGS;
}
