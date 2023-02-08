#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define MAX_ROWS 10
#define MAX_COLS 10

#define SIZE_INPUT_ERROR -1
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


int digit_is_valid(int *digit)
{
    if (scanf("%d", digit) != 1)
    {   
        printf("Digit input error");
        
        return ELEMENT_INPUT_ERROR;
    }

    if (*digit > 9 || *digit < 0)
    {   
        printf("Digit input error");

        return ELEMENT_INPUT_ERROR;
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


int first_digit(int element, const int digit)
{
    element = abs(element);
    
    while (element > 9)
        element = element / 10;
    
    if (element == digit)
        return 1;

    return 0;
}


int last_digit(int element, const int digit)
{
    element = abs(element) % 10;

    if (element == digit)
        return 1;
    
    return 0;
}


void insert_row(int (*matrix)[MAX_COLS], const size_t index, const size_t rows, const size_t cols)
{
    for (size_t i = rows - 1; i > index; i--)
        for (size_t j = 0; j < cols; j++)
            matrix[i + 1][j] = matrix[i][j];

    for (size_t i = 0; i < cols; i++)
        matrix[index + 1][i] = 100;
}


void arr_to_matrix(int (*matrix)[MAX_COLS], size_t *rows, size_t cols, int *arr, size_t array_len)
{
    for (size_t i = 0; i < array_len; i++)
    {
        insert_row(matrix, arr[i], *rows, cols);
        arr[i + 1] += i + 1;
        *rows = *rows + 1;
    }
}


void find_rows(int (*const matrix)[MAX_COLS], const size_t rows, const size_t cols, const int digit, int *arr, size_t *array_len)
{     
    for (size_t i = 0; i < rows; i++)
    {   
        int count_first_digit = 0, count_last_digit = 0;
        
        for (size_t j = 0; j < cols; j++)
        {
            if (first_digit(matrix[i][j], digit))
                count_first_digit++;
            if (last_digit(matrix[i][j], digit))
                count_last_digit++;
        }
        if ((count_first_digit > 0) && (count_first_digit == count_last_digit))
        {
            arr[*array_len] = i;
            *array_len = *array_len + 1;
        }
    }
}


int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS], input_rows, input_cols, digit, arr[ARRAY_SIZE];
    
    int size_check = size_is_valid(&input_rows, &input_cols);

    if (size_check == ELEMENT_INPUT_ERROR)
        return ELEMENT_INPUT_ERROR;
    if (size_check == SIZE_INPUT_ERROR)
        return SIZE_INPUT_ERROR;

    size_t rows = input_rows;
    size_t cols = input_cols;
    size_t array_len = 0;

    if (input_matrix(matrix, rows, cols) == ELEMENT_INPUT_ERROR)
    {
        printf("Input error");

        return ELEMENT_INPUT_ERROR;
    }
    
    int digit_check = digit_is_valid(&digit);

    if (digit_check == ELEMENT_INPUT_ERROR)
        return ELEMENT_INPUT_ERROR;

    find_rows(matrix, rows, cols, digit, arr, &array_len);

    arr_to_matrix(matrix, &rows, cols, arr, array_len);

    print_matrix(matrix, rows, cols);

    return EXIT_SUCCESS;
}
