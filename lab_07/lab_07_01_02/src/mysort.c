#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "errs_defs.h"
#include "mysort.h"

int key(int *start, int *end, int **new_array_start, int **new_array_end)
{
    if (start > end)
        return ERR_WRONG_POINTERS;
    
    size_t count_size = 0;

    for (int *i = start; i < end && *i >= 0; i++)
        count_size++;

    if (count_size == EMPTY)
        return ERR_EMPTY_ARRAY;
    
    int *new_array = (int*)malloc(count_size * sizeof(int));

    *new_array_start = new_array;
    *new_array_end = new_array + count_size;

    for (int *i = *new_array_start, *j = start; i < *new_array_end; i++, j++)
        *i = *j;
	
    return EXIT_SUCCESS;
}

int compare_int(const void *value_1, const void *value_2)
{
    const int *temp_1 = value_1;
    const int *temp_2 = value_2;
    
    return *temp_1 - *temp_2; 
}

int swap(void *value_1, void *value_2, size_t size)
{
    char *buffer = malloc(size);
    
    if (buffer == NULL)
        return ERR_MALLOC;

    memcpy(buffer, value_1, size);
    memcpy(value_1, value_2, size);
    memcpy(value_2, buffer, size);
    free(buffer);

    return EXIT_SUCCESS;
}

int mysort(void *array, size_t count, size_t size, int (*compare_int)(const void*, const void*))
{
    for (size_t i = 0; i < count; i++)
        for (size_t j = 0; j < count - 1; j++)
            if ((*compare_int)((uint8_t *)array + j * size, (uint8_t *)array + j * size + size) > 0)
                if ((swap(((uint8_t *)array + j * size), ((uint8_t *)array + j * size + size), size)) != EXIT_SUCCESS)
                    return ERR_MALLOC;
    
    return EXIT_SUCCESS;
}
