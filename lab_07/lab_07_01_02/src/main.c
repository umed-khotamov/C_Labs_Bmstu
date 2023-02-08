#include <stdio.h>
#include <stdlib.h>

#include "errs_defs.h"
#include "get_command.h"
#include "io_file.h"
#include "mysort.h"

int main(const int argc, const char *argv[])
{
    int *array = NULL;
    int command = 0;
    int return_code = 0;
    size_t size = 0;
    const char *in_filename = argv[FILE_IN], *out_filename = argv[FILE_OUT];
    
    if ((return_code = get_command(argc, argv, &command)) != EXIT_SUCCESS)
        return return_code;
    if ((return_code = init_array(in_filename, &array, &size)) != EXIT_SUCCESS)
        return return_code;

    int *start = array;
    int *end = start + size;
    int *new_array_start = NULL; 
    int *new_array_end = NULL;
    switch (command)
    {
        case SORT:
            if ((return_code = mysort(array, size, sizeof(array[0]), compare_int)) != EXIT_SUCCESS)
            {
                free(array);
                return return_code;
            }
            write_to_file(out_filename, start, end);
            break;
        case FILTER_SORT:
            if ((return_code = key(start, end, &new_array_start, &new_array_end)) != EXIT_SUCCESS)
            {
                free(array);
                return return_code;
            }
            size_t new_array_size = new_array_end - new_array_start;
            if ((return_code = mysort(new_array_start, new_array_size, sizeof(*new_array_start), compare_int)) != EXIT_SUCCESS)
            {
                free(new_array_start);
                return return_code;
            }
            write_to_file(out_filename, new_array_start, new_array_end);
            break;
    }
    free(array);
    free(new_array_start);

    return EXIT_SUCCESS;
}
