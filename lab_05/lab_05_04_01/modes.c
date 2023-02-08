#include "funcs.h"
#include "modes.h"

int mode_one(FILE *file)
{   
    if (file == NULL)
        return FILE_OPEN_ERROR;

    int return_code = get_student(file);
    
    if (return_code)
        return return_code;
    
    return_code = sort_student(file);
        
    if (return_code)
        return return_code;
    
    print_file(file);

    return EXIT_SUCCESS;
}


int mode_two(FILE *file_in, FILE *file_out, char **argv)
{
    if (file_in == NULL || file_out == NULL)
        return FILE_OPEN_ERROR;

    int return_code = get_student(file_in);
    
    if (return_code)
    {
        fclose(file_in);

        return return_code;
    }
    
    return_code = find_surname(file_in, file_out, argv[4]);
    
    if (return_code)
    {
        fclose(file_in);
        fclose(file_out);
        
        return return_code;
    }
    
    return EXIT_SUCCESS;
}

int mode_three(FILE *file, FILE *new_file, char **argv)
{
    if (file == NULL)
        return FILE_OPEN_ERROR;

    int return_code = get_student(file);
        
    if (return_code)
    {
        fclose(file);

        return return_code;
    }
    make_new_file(file, new_file);

    fclose(file);
    fclose(new_file);

    FILE *in_file = fopen(argv[2], "wb");
    FILE *out_file = fopen("new_data.bin", "rb");

    rewrite_file(in_file, out_file);

    fclose(in_file);
    fclose(out_file);

    return EXIT_SUCCESS;
}
