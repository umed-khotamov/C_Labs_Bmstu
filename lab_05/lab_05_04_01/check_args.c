#include "funcs.h"
#include "check_args.h"

int check_args(int argc, char **argv, int *mode)
{
    if (argc == 3 && strcmp(argv[1], "sb") == 0)
        *mode = 1;

    else if (argc == 5 && strcmp(argv[1], "fb") == 0)
        *mode = 2;

    else if (argc == 3 && strcmp(argv[1], "db") == 0)
        *mode = 3;
    else
        return ARGUMENT_INPUT_ERROR;

    return EXIT_SUCCESS;
}
