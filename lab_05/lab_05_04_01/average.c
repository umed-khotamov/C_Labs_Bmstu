#include "funcs.h"

double get_average(int *array)
{
    double sum = 0, counter = 0;

    for (int i = 0; i < MAX_MARKS; i++)
    {
        sum += array[i];
        counter++;
    }

    return sum / counter;
}


double get_overall_average(FILE *file)
{
    student_t value;

    size_t size = 0;

    file_size(file, &size);

    size = size / sizeof(student_t);
    
    double sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(file, i, &value);
        sum += get_average(value.mark);
    }

    return sum / size;
}


void make_new_file(FILE *file, FILE *new_file)
{
    student_t value;

    double overall_average = get_overall_average(file);
    
    rewind(file);

    size_t size = 0;
    file_size(file, &size);
    size = size / sizeof(student_t);
    
    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(file, i, &value);

        if (fabs(get_average(value.mark) - overall_average) < EPS || (get_average(value.mark) - overall_average) >= EPS)
            fwrite(&value, sizeof(student_t), 1, new_file);
    }
}


void rewrite_file(FILE *file_in, FILE *file_out)
{
    student_t value;

    size_t size = 0;
    
    file_size(file_out, &size);
    
    size = size / sizeof(student_t);

    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(file_out, i, &value);
        fwrite(&value, sizeof(student_t), 1, file_in);
    }
}
