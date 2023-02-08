#include "get_and_put.h"

int get_number_by_pos(FILE *file, size_t pos, int *num)
{
    pos = pos * sizeof(int);

    int rc = fseek(file, pos, SEEK_SET);
    
    if (rc == 0)
    {
        rc = fread(num, sizeof(int), 1, file);

        if (rc != 1)
            return FILE_READ_ERROR;
    }
    else
        return FILE_READ_ERROR;
    
    return EXIT_SUCCESS;
}

int put_number_by_pos(FILE *file, size_t pos, int num)
{
    pos = pos * sizeof(int);

    int rc = fseek(file, pos, SEEK_SET);

    if (rc == 0)
    {
        rc = fwrite(&num, sizeof(int), 1, file);

        if (rc != 1)
            return FILE_WRITE_ERROR;
    }
    else
        return FILE_READ_ERROR;

    return EXIT_SUCCESS;
}
