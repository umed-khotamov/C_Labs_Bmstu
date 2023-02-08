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


int input_matrix(int (*matrix)[MAX_COLS], const size_t rows, const size_t cols)
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


void print_matrix(int (*const matrix)[MAX_COLS], const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}


int sum(const int *const row, const size_t len)
{
    int total = 0;

    for (size_t i = 0; i < len; i++)
        total += row[i];
    
    return total;
}


void replace_rows(int *a, int *b, const size_t cols)
{
    for (size_t i = 0; i < cols; i++)
    {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}


void matrix_sort(int (*matrix)[MAX_COLS], const size_t rows, const size_t cols)
{    
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rows - 1; j++)
        {
            if (sum(matrix[j], cols) > sum(matrix[j + 1], cols))
            {
                replace_rows(matrix[j], matrix[j + 1], cols);
            }
        }
    }
}


int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS], input_rows, input_cols;
    
    int size_check = size_is_valid(&input_rows, &input_cols);

    if (size_check == ELEMENT_INPUT_ERROR)
        return ELEMENT_INPUT_ERROR;
    if (size_check == SIZE_INPUT_ERROR)
        return SIZE_INPUT_ERROR;

    size_t rows = input_rows;
    size_t cols = input_cols;

    if (input_matrix(matrix, rows, cols) == ELEMENT_INPUT_ERROR)
    {
        printf("Input error");

        return ELEMENT_INPUT_ERROR;
    }
    matrix_sort(matrix, rows, cols);

    print_matrix(matrix, rows, cols);

    return EXIT_SUCCESS;
}

