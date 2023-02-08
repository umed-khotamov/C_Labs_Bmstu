#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ROWS 10
#define MAX_COLS 10

#define SIZE_INPUT_ERROR 1
#define ELEMENT_INPUT_ERROR 2
#define NO_ODD_VALUES 3


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


int is_odd(int value)
{
    value = abs(value);
    if (value % 2 == 1)
        return 1;
    
    return 0;
}


int find_min(int (*const matrix)[MAX_COLS], const size_t rows, int min)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (is_odd(matrix[i][j]) && matrix[i][j] < min)
                min = matrix[i][j];
        }
    }

    return min;
}


int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS], input_rows, input_cols;
    
    int size_check = size_is_valid(&input_rows, &input_cols);

    if (size_check == ELEMENT_INPUT_ERROR)
        return ELEMENT_INPUT_ERROR;
    if (size_check == SIZE_INPUT_ERROR)
        return SIZE_INPUT_ERROR;

    if (input_cols != input_rows)
    {
        printf("Matrix must be squared");

        return SIZE_INPUT_ERROR;
    }

    size_t rows = input_rows;
    size_t cols = input_cols;
    int min = INT_MAX;

    if (input_matrix(matrix, rows, cols) == ELEMENT_INPUT_ERROR)
    {
        printf("Input error");

        return ELEMENT_INPUT_ERROR;
    }

    int get_min = find_min(matrix, rows, min);

    if (get_min == INT_MAX)
    {
        printf("No odd values");

        return NO_ODD_VALUES;
    }
    
    printf("%d\n", get_min);
    
    return EXIT_SUCCESS;
}
