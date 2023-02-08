#include "funcs.h"

int get_student_by_pos(FILE *file, size_t pos, student_t *value)
{
    pos = pos * sizeof(student_t);
       
    fseek(file, pos, SEEK_SET);
    
    int rc = fread(value, sizeof(student_t), 1, file);
    
    if (rc != 1)
        return FILE_READ_ERROR;

    return EXIT_SUCCESS;
}

void put_student_by_pos(FILE *file, size_t pos, student_t value)
{
    pos = pos * sizeof(student_t);

    fseek(file, pos, SEEK_SET);
    fwrite(&value, sizeof(student_t), 1, file);
}
