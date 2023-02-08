#include "funcs.h"
#include "check_args.h"
#include "modes.h"

int main(int argc, char **argv)
{
    int mode = 0;
    int return_code = check_args(argc, argv, &mode);
    
    if (return_code)
        return return_code;

    if (mode == 1)
    {
        FILE *file = fopen(argv[2], "r+b");
        return_code = mode_one(file);
        
        if (return_code)    
            return return_code;

        fclose(file);
    }
    if (mode == 2)
    {
        FILE *file_in = fopen(argv[2], "rb");
        FILE *file_out = fopen(argv[3], "wb");
        return_code = mode_two(file_in, file_out, argv);

        if (return_code)
            return return_code;

        fclose(file_in);
        fclose(file_out);
    }
    if (mode == 3)
    {
        FILE *file = fopen(argv[2], "rb");
        FILE *new_file = fopen("new_data.bin", "wb");
        return_code = mode_three(file, new_file, argv);
        
        if (return_code)
            return return_code;
    }
    return EXIT_SUCCESS;
}

