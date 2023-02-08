#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "types_defs.h"
#include "sort_array.h"

double comparator(const void *value_1, const void *value_2)
{
    const subject_t *temp_1 = value_1;
    const subject_t *temp_2 = value_2;
    
    return (temp_1->weight / temp_1->volume) - (temp_2->weight / temp_2->volume);
}

void swap(void *value_1, void *value_2, size_t size)
{
    char *buffer = malloc(size);
    
    memcpy(buffer, value_1, size);
    memcpy(value_1, value_2, size);
    memcpy(value_2, buffer, size);
    free(buffer);
}

void mysort(void *array, int element_size, size_t array_size, double (*comparator)(const void*, const void*))
{
    for (size_t i = 0; i < array_size; i++)
        for (size_t j = 0; j < array_size - 1; j++)
            if ((*comparator)((uint8_t *)array + j * element_size, (uint8_t *)array + j * element_size + element_size) > 0)
                swap((uint8_t *)array + j * element_size, (uint8_t *)array + j * element_size + element_size, element_size);
}
