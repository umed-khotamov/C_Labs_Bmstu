#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "errs_defs.h"
#include "funcs.h"

typedef void (*write_to_file_t) (const char *filename, int *start, int *end);
typedef int (*init_array_t) (const char *filename, int **array, size_t *size);
typedef int (*fkey_t) (int *start, int *end, int **new_array_start, int **new_array_end);
typedef int (*my_sort_t) (void *array, size_t count, size_t size, int (*compare_int) (const void *, const void *));
typedef int (*compare_t) (const void *value_1, const void *value_2);

int main(const int argc, const char *argv[])
{
    void *my_lib = dlopen("./libs/load_lib.so", RTLD_NOW);

    if (!my_lib)
        return ERR_OPEN_LIB;

    int *array = NULL;
    int command = 0;
    int return_code = 0;
    size_t size = 0;
    const char *in_filename = argv[FILE_IN], *out_filename = argv[FILE_OUT];
    
    if ((return_code = get_command(argc, argv, &command)) != EXIT_SUCCESS)
        return return_code;
    
    init_array_t init_array = dlsym(my_lib, "init_array");
    if (!init_array)
        return ERR_LOAD;
    
    my_sort_t mysort = dlsym(my_lib, "mysort");
    if (!mysort)
        return ERR_LOAD;
    
    write_to_file_t write_to_file = dlsym(my_lib, "write_to_file");
    if (!write_to_file)
        return ERR_LOAD;

    fkey_t key = dlsym(my_lib, "key");
    if (!key)
        return ERR_LOAD;
    
    compare_t compare_int = dlsym(my_lib, "compare_int");
    if (!compare_int)
        return ERR_LOAD;

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
            init_new_array(start, end, &new_array_start, &new_array_end);
            key(start, end, &new_array_start, &new_array_end);
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
    dlclose(my_lib);

    return EXIT_SUCCESS;
}
