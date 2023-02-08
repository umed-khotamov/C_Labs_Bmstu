#include "funcs.h"

void print_struct(student_t value)
{
    printf("%s\n", value.surname);
    printf("%s\n", value.name);
        
    for (int i = 0; i < MAX_MARKS; i++)
        printf("%u ", value.mark[i]);

    printf("\n");
}


void print_file(FILE *file)
{
    fseek(file, 0L, SEEK_SET);

    student_t value;

    size_t size = 0;
    file_size(file, &size);
    size = size / sizeof(student_t);

    for (size_t i = 0; i < size; i++)
    {
        fread(&value, sizeof(student_t), 1, file);
        print_struct(value);
    }
}
