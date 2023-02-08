#include "funcs.h"

int file_size(FILE *file, size_t *size)
{
    long get_size = 0;

    if (fseek(file, 0L, SEEK_END))
        return FILE_OPEN_ERROR;

    get_size = ftell(file);

    if (get_size <= 0)
        return FILE_OPEN_ERROR;

    *size = get_size;

    return fseek(file, 0L, SEEK_SET);
}


int get_student(FILE *file)
{
    student_t get_field;

    size_t size = 0, read = 0;
    
    file_size(file, &size);

    if (size <= 0)
        return FILE_SIZE_ERROR;

    size = size / sizeof(student_t);
    
    for (size_t i = 0; i < size; i++)
    {
        read = fread(&get_field, sizeof(student_t), 1, file);
        
        if (strlen(get_field.surname) <= 0)
            return SURNAME_SIZE_ERROR;
        if (strlen(get_field.name) <= 0)
            return NAME_SIZE_ERROR;
        
        for (size_t j = 0; j < MAX_MARKS; j++)
            if (get_field.mark[j] <= 0)
                return MARK_ERROR;

        if (read != 1)
            return FILE_READ_ERROR;
    }

    return EXIT_SUCCESS;
}
