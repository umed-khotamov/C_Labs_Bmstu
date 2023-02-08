#include "check_args.h"
#include "get_and_put.h"

int check_args(int argc, char **argv, int *mode)
{
    if ((argc != 3) && (argc != 4))
        return ARGUMENT_INPUT_ERROR;
    
    if (strcmp(argv[1], "c") == 0 && argc == 4)
        *mode = 1;
    
    else if (strcmp(argv[1], "p") == 0 && argc == 3)
        *mode = 2;

    else if (strcmp(argv[1], "s") == 0 && argc == 3)
        *mode = 3;
    
    else
        return NOT_ENOUGH_ARGUMENTS;
    
    return EXIT_SUCCESS;
}
