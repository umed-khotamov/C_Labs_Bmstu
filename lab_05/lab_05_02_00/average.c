#include "average.h"

int find_average(FILE *file, double *average)
{
    int counter = 0;

    double sum = 0, element;

    if (fscanf(file, "%lf", &element) != 1)
        return NO_DATA;
    
    sum += element;
    counter++;

    while (fscanf(file, "%lf", &element) == 1)
    {
        sum += element;
        counter++;
    }
    if (counter == 1)
        return FILE_INPUT_ERROR;

    *average = sum / counter;

    return EXIT_SUCCESS;
}

double find_close_to_average(FILE *file, double average)
{
    double max_to_av = 0, i = 0, element;
   
    fscanf(file, "%lf", &element);
    
    max_to_av = fabs(average - element);

    i = element;

    while (fscanf(file, "%lf", &element) == 1)
    {
        if (fabs(average - element) < max_to_av)
        {
            max_to_av = fabs(average - element);
            i = element;
        }
    }

    return i;
}
