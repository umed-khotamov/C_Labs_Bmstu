#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define ARRAY_SIZE 10

#define SIZE_INPUT_ERROR 1
#define ELEMENT_INPUT_ERROR 2


int size_is_valid(int *const rows, int *const cols)
{
    if (scanf("%d", rows) != 1 || scanf("%d", cols) != 1)
    {
        printf("Element input error");

        return ELEMENT_INPUT_ERROR;
    }
    
    if ((*rows > MAX_ROWS || *rows <= 0) || (*cols > MAX_COLS || *cols <= 0))
    {   
        printf("Size input error");

        return SIZE_INPUT_ERROR;
    }

    return EXIT_SUCCESS;
}


int input_matrix(int matrix[][MAX_COLS], const size_t rows, const size_t cols)
{
    int element;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (scanf("%d", &element) != 1)
                return ELEMENT_INPUT_ERROR;

            matrix[i][j] = element;
        }
    }
    
    return EXIT_SUCCESS;
}


int descended_sort_column(int (*const matrix)[MAX_COLS], size_t rows, const size_t cols, int *array, size_t *array_len)
{   
    size_t k = 0;

    if (rows == 1)
    {
        for (; k < cols; k++)
            array[k] = 0;

        *array_len = k;

        return 1;
    }

    for (size_t i = 0; i < cols; i++)
    {   
        int flag = 1;

        for (size_t j = 0; j < rows - 1; j++)
        {
            if (matrix[j][i] <= matrix[j + 1][i])
                flag = 0;
        }
        if (flag)
            array[k] = 1;
        else
            array[k] = 0;
        k++;
    }

    *array_len = k;

    return 1;
}


void print_array(const int *const array, const size_t array_len)
{
    for (size_t i = 0; i < array_len; i++)
        printf("%d ", array[i]);
}


int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS], array[ARRAY_SIZE], input_rows, input_cols;
    
    int size_check = size_is_valid(&input_rows, &input_cols);

    if (size_check == ELEMENT_INPUT_ERROR)
        return ELEMENT_INPUT_ERROR;
    if (size_check == SIZE_INPUT_ERROR)
        return SIZE_INPUT_ERROR;

    size_t array_len = 0;
    size_t rows = input_rows;
    size_t cols = input_cols;
    
    if (input_matrix(matrix, rows, cols) == ELEMENT_INPUT_ERROR)
    {
        printf("Input error");

        return ELEMENT_INPUT_ERROR;
    }

    if (descended_sort_column(matrix, rows, cols, array, &array_len))
        print_array(array, array_len);

    return EXIT_SUCCESS;
}

