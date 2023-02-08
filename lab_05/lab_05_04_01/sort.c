#include "funcs.h"

int sort_student(FILE *file)
{
    student_t student_1, student_2;
    
    int rc = 0;
    size_t size = 0;
    file_size(file, &size);
    size = size / sizeof(student_t);
    
    size_t i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
        {   
            rc = get_student_by_pos(file, j, &student_1);
            if (rc)
                return rc;
            rc = get_student_by_pos(file, j + 1, &student_2);
            if (rc)
                return rc;
            
            if (strcmp(student_1.surname, student_2.surname) > 0)
            {
                put_student_by_pos(file, j, student_2);
                put_student_by_pos(file, j + 1, student_1);
            }
            if (strcmp(student_1.surname, student_2.surname) == 0)
                if (strcmp(student_1.name, student_2.name) > 0)
                {
                    put_student_by_pos(file, j, student_2);
                    put_student_by_pos(file, j + 1, student_1);
                }
        }

    return EXIT_SUCCESS;
}
