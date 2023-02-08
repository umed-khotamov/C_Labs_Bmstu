#include <stdio.h>
#include <stdlib.h>

#include "errs_defs.h"
#include "matrix.h"

int **get_copy(int **matrix, size_t rows, size_t cols, int **new_matrix)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            new_matrix[i][j] = matrix[i][j];
    
    return new_matrix;
}

void add_row(int **matrix, size_t *rows)
{
    size_t temp_rows = *rows;
    size_t i, j;

    for (i = 0; i < temp_rows; i++)
    {
        int sum = 0;
        int avg = 0;

        for (j = 0; j < temp_rows; j++)
            sum += matrix[j][i];

        avg = sum / temp_rows;
        matrix[j][i] = avg;
    }

    temp_rows++;
    *rows = temp_rows;
}

void add_col(int **matrix, size_t rows, size_t *cols)
{
    size_t temp_cols = *cols;
    size_t i, j;
    int max;

    for (i = 0; i < rows; i++)
    {
        max = matrix[i][0];
        for (j = 0; j < temp_cols; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];

        matrix[i][j] = max;
    }

    temp_cols++;
    *cols = temp_cols;
}

int del_option(size_t rows, size_t cols)
{
    if (rows == cols)
        return EQUAL;

    return (rows > cols) ? DELROWS : DELCOLS;
}

void del_row(int **matrix, size_t *rows, size_t cols)
{
    size_t temp_rows = *rows;
    size_t max_index = 0;
    size_t index_col = 0;

    find_max(matrix, temp_rows, cols, &max_index, &index_col);
    
    for (size_t i = max_index; i < temp_rows - 1; i++)
        for (size_t j = 0; j < cols; j++)
            matrix[i][j] = matrix[i + 1][j];
    
    temp_rows--;
    *rows = temp_rows;
}

void del_col(int **matrix, size_t rows, size_t *cols)
{
    size_t temp_cols = *cols;
    size_t max_index = 0;
    size_t index_row = 0;

    find_max(matrix, rows, temp_cols, &index_row, &max_index);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = max_index; j < temp_cols - 1; j++)
            matrix[i][j] = matrix[i][j + 1];
    
    temp_cols--;
    *cols = temp_cols; 
}

void find_max(int **matrix, size_t rows, size_t cols, size_t *inrow, size_t *incol)
{
    int max = matrix[0][0];
    
    size_t i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            if (matrix[i][j] > max)
                max = matrix[i][j];
    
    int fmax_found = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            if (matrix[i][j] == max)
            {
                fmax_found = 1;
                *incol = j;
            }
        if (fmax_found)
            break;
    }
    *inrow = i;
}

int fill_matrix(int **matrix, size_t rows, size_t cols)
{
    int element = 0;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            if ((scanf("%d", &element)) != 1)
                return ERELINPUT;

            matrix[i][j] = element;
        }

    return EXIT_SUCCESS;
}

void print_matrix(int **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int **alloc_matrix(size_t rows, size_t cols)
{
    int **matrix = malloc(rows * sizeof(int*));
    
    if (matrix == NULL)
        return NULL;

    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(int));
        
        if (matrix[i] == NULL)
        {
            free_matrix(matrix, rows);
            
            return NULL;
        }
    }
    
    return matrix;
}

void free_matrix(int **matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
        free(matrix[i]);

    free(matrix);
}
