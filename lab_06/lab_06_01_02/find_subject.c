#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types_defs.h"
#include "find_subject.h"

int has_prefix(const char *const string, const char *substring)
{
    if (strncmp(string, substring, strlen(substring)) != 0)
        return NO_MATCHES;

    return EXIT_SUCCESS;
}

int find_subject(const subject_t *array, const size_t array_size, const char *substring)
{
    for (size_t i = 0; i < array_size; i++)
        if (has_prefix(array[i].subject, substring) != NO_MATCHES)
            printf("%s\n%lf\n%lf\n", array[i].subject, array[i].weight, array[i].volume);
    
    return EXIT_SUCCESS;
}
