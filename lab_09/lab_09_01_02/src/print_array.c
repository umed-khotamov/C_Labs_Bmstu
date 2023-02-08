#include <stdlib.h>
#include <stdio.h>

#include "types_defs.h"
#include "print_array.h"

void print_array(const subject_t *array, const size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
        printf("%s%lf\n%lf\n", array[i].subject, array[i].weight, array[i].volume);
}
