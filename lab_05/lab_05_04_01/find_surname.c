#include "funcs.h"

int find_surname(FILE *file_in, FILE *file_out, char *string)
{
    student_t value;

    size_t size = 0;
    file_size(file_in, &size);
    size = size / sizeof(student_t);
    
    int flag = 0;

    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(file_in, i, &value);

        char *check_substring = strstr(value.surname, string);
        if (check_substring)
        {
            flag = 1;
            fwrite(&value, sizeof(student_t), 1, file_out);
        }
    }
    if (!flag)
        return NO_MATCHES_FOUND;
    
    return EXIT_SUCCESS;
}
