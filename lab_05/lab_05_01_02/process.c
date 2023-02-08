#include "process.h"

int process(FILE *file, int *index)
{
    int max, curr_max, flag = 0, position = 0;

    if (fscanf(file, "%d", &max) != 1)
        return NO_DATA;
    
    position++;
    *index = position;

    while (fscanf(file, "%d", &curr_max) == 1)
    {
        flag = 1;
            
        position++;

        if (max < curr_max)
        {
            max = curr_max;
            *index = position;
        }
    }
    if (!flag)
        return EXIT_SUCCESS;

    return EXIT_SUCCESS;
}
