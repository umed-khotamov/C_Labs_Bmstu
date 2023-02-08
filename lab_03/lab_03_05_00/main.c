#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define ARRAY_SIZE 10

#define SIZE_INPUT_ERROR 1
#define ELEMENT_INPUT_ERROR 2
#define NO_PRIME_VALUES 3


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


int is_prime(int n)
{
    if (n > 1)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0) 
                return 0;
        }

        return 1;
    }
    else 
        return 0;
}


void reverse_array(int *array, const size_t array_len)
{
    for (size_t i = 0; i < array_len / 2; i++)
    {
        int temp = array[i];
        array[i] = array[array_len - i - 1];
        array[array_len - i - 1] = temp; 
    }
}


int init_array(int (*const matrix)[MAX_COLS], const size_t rows, const size_t cols, int *array, size_t *array_len)
{
    size_t index = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                array[index] = matrix[i][j];
                index++;
            }
        }
    }
    *array_len = index;

    if (*array_len == 0)
        return NO_PRIME_VALUES;
    
    return EXIT_SUCCESS;
}


void arr_to_matrix(int (*matrix)[MAX_COLS], const int *const array, const size_t rows, const size_t cols)
{
    size_t index = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                matrix[i][j] = array[index];
                index++;
            }
        }
    }
}


void print_array(const int *array, const size_t array_len)
{
    for (size_t i = 0; i < array_len; i++)
        printf("%d ", array[i]);
}


int main(void)
{
    int matrix[MAX_ROWS][MAX_COLS], input_rows, input_cols, array[ARRAY_SIZE];
    
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
    if (init_array(matrix, rows, cols, array, &array_len) == NO_PRIME_VALUES)
    {
        printf("No prime values");

        return NO_PRIME_VALUES;
    }
    reverse_array(array, array_len);

    arr_to_matrix(matrix, array, rows, cols);

    print_matrix(matrix, rows, cols);

    return EXIT_SUCCESS;
}
