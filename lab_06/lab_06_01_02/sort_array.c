#include <stdlib.h>

#include "types_defs.h"
#include "sort_array.h"

void swap(subject_t *value_1, subject_t *value_2)
{
    subject_t temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}

void bubble_sort(subject_t *array, const size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
        for (size_t j = 0; j < array_size - 1; j++)
            if ((array[j].weight / array[j].volume) > (array[j + 1].weight / array[j + 1].volume))
                swap(&array[j], &array[j + 1]); 
}
