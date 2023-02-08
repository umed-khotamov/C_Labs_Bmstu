#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

#define ELEMENT_INPUT_ERROR 1
#define SIZE_INPUT_ERROR 2


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


int input_matrix(int (*matrix)[MAX_COLS], size_t rows, size_t cols)
{
    int element = 0;
    int row = rows;
    int col = cols;

    for (int i = 1; i < col + 1; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j < row + 1; j++)
                matrix[j - 1][i - 1] = ++element;
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
                matrix[j][i - 1] = ++element;
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
    
    input_matrix(matrix, rows, cols);

    print_matrix(matrix, rows, cols);

    return EXIT_SUCCESS;
}
