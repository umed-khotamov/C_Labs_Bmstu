#include <string.h>
#include <stdlib.h>

#include "types_defs.h"
#include "get_command.h"

int check_args(const int argc, const char *argv[], int *command)
{
    if (argc == MIN_ARGS)
        *command = SORT_ARRAY;
    else if (argc == MAX_ARGS && strcmp(argv[2], KEY) == 0)
        *command = PRINT_ARRAY;
    else if (argc == MAX_ARGS)
        *command = FIND_SUBJECT;

    return *command ? EXIT_SUCCESS : ERROR_ARGS; 
}
