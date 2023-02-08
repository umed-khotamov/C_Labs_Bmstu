#include <stdio.h>
#include <stdlib.h>

#include "errs_defs.h"
#include "io_file.h"

int get_file_size(const char *filename, size_t *size)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return ERR_FILE_OPEN;

    size_t temp = 0;
    int element = 0;

    while (fscanf(file, "%d", &element) == 1)
        temp++;
    *size = temp;
    
    fclose(file);

    return temp ? EXIT_SUCCESS : ERR_EMPTY_FILE;
}

int fill_array(const char *filename, int **array, size_t size)
{
    FILE *file = fopen(filename, "r");

    *array = (int*)malloc(size * sizeof(int));

    if (*array == NULL)
    {
        fclose(file);   
        return ERR_MALLOC;
    }
    int *start = *array;
    int *end = start + size;

    for (int *i = start; i < end; i++)
            fscanf(file, "%d", i);
    
    fclose(file);
    
    return EXIT_SUCCESS;
}

void write_to_file(const char *filename, int *start, int *end)
{
    FILE *file = fopen(filename, "w");
   
    for (int *i = start; i < end; i++)
        fprintf(file, "%d ", *i);
    fprintf(file, "\n");

    fclose(file);
}

int init_array(const char *filename, int **array, size_t *size)
{
    int return_code = 0;
    size_t temp_size = 0;
    if ((return_code = get_file_size(filename, &temp_size)) != EXIT_SUCCESS)
        return return_code;
    if ((return_code = fill_array(filename, array, temp_size)) != EXIT_SUCCESS)
        return return_code;
    
    *size = temp_size;

    return EXIT_SUCCESS;
}
