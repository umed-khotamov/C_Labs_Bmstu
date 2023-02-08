#include "commands.h"

int main(int argc, char **argv)
{
    int mode = 0;

    int return_code = check_args(argc, argv, &mode);

    if (mode == 1)
        return_code = write_random(argv[2], argv);

    if (mode == 2)
        return_code = print_file(argv);
        
    if (mode == 3)
        return_code = file_sort(argv);

    if (return_code)
        return return_code;

    return EXIT_SUCCESS;
}
