#include "commands.h"


int file_size(FILE *file, size_t *size)
{
    long get_size = 0;

    if (fseek(file, 0L, SEEK_END))
        return FILE_OPEN_ERROR;

    get_size = ftell(file);

    if (get_size < 0)
        return FILE_OPEN_ERROR;

    *size = get_size;

    return fseek(file, 0L, SEEK_SET);
}

int write_random(char *string, char **argv)
{
    FILE *file = fopen(argv[3], "wb");

    if (file == NULL)
        return FILE_OPEN_ERROR;
    
    int num = atoi(string);

    int value = 0;

    srand((unsigned int)time(NULL));

    if (num <= 0 || num > 50)
        return NUMBER_INPUT_ERROR;

    for (int i = 0; i < num; i++)
    {
        value = rand() % 100;

        size_t wrote = fwrite(&value, sizeof(int), 1, file);

        if (wrote != 1)
            return FILE_WRITE_ERROR;
    }
    fclose(file);

    return EXIT_SUCCESS;
}

int print_file(char **argv)
{
    FILE *file = fopen(argv[2], "rb");
    
    if (file == NULL)
        return FILE_OPEN_ERROR;

    int num = 0;

    size_t size = 0, read;

    int rc = file_size(file, &size);

    if (size < sizeof(int) || rc)
        return FILE_SIZE_ERROR;

    for (size_t i = 0; i < size / sizeof(int); i++)
    {
        read = fread(&num, sizeof(int), 1, file);

        if (read == 1)
            printf("%d ", num);
        else
            return FILE_READ_ERROR;
    }
    fclose(file);

    return EXIT_SUCCESS;
}

int file_sort(char **argv)
{
    FILE *file = fopen(argv[2], "r+b");

    if (file == NULL)
        return FILE_OPEN_ERROR;

    size_t size = 0;

    int value_1 = 0, value_2 = 0;

    int rc = file_size(file, &size);
    
    size = size / sizeof(int);

    if (size == 0 || rc)
        return FILE_SIZE_ERROR;

    size_t i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
        {
            get_number_by_pos(file, j, &value_1);
            get_number_by_pos(file, j + 1, &value_2);
            
            if (value_1 == FILE_READ_ERROR || value_2 == FILE_READ_ERROR)
                return FILE_READ_ERROR;

            if (value_1 > value_2)
            {
                rc = put_number_by_pos(file, j, value_2);
                
                if (rc)
                    return rc;

                rc = put_number_by_pos(file, j + 1, value_1);
                
                if (rc)
                    return rc;
            }
        }
    fclose(file);

    return EXIT_SUCCESS;
}
