#include <stdio.h>
#include <stdlib.h>

#include "types_defs.h"
#include "get_command.h"
#include "read_file.h"
#include "sort_array.h"
#include "find_subject.h"
#include "print_array.h"

int main(int argc, const char *argv[])
{   
    int return_code = 0;
    int command = 0;
    size_t array_size = 0;
    
    const char *filename = argv[MIN_ARGS - 1];
    const char *substring = argv[MAX_ARGS - 1];
    
    if ((return_code = check_args(argc, argv, &command)) != EXIT_SUCCESS) 
        return return_code;
    
    if ((return_code = read_file(filename, &array_size)) != EXIT_SUCCESS)
        return return_code;
    
    if ((return_code = size_is_valid(array_size)) != EXIT_SUCCESS)
        return return_code;
    
    subject_t *array = malloc(array_size * sizeof(subject_t));

    if (array == NULL)
        return ERMALLOC;
    
    if ((return_code = fill_array(filename, array, array_size)) != EXIT_SUCCESS)
    {
        free_struct(array, array_size);
        return return_code;
    }
    switch (command)
    {
        case SORT_ARRAY:
            mysort(array, sizeof(array[0]), array_size, comparator);
            print_array(array, array_size);
            break;
        case PRINT_ARRAY:
            print_array(array, array_size);
            break;
        case FIND_SUBJECT:
            find_subject(array, array_size, substring);
            break;
    }
    free_struct(array, array_size);

    return EXIT_SUCCESS;
}
