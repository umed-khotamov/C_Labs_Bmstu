#include <stdio.h>
#include <stdlib.h>

#include "errs_defs.h"
#include "matrix.h"
#include "matrix_math.h"

void identity_matrix(int **matrix, size_t size)
{
    for (size_t i = 0; i < size; i++) 
        for (size_t j = 0; j < size; j++)
            matrix[i][j] = i == j;
}

void power_matrix(int **matrix, int **res_matrix, size_t size, int power)
{
    int **temp = alloc_matrix(size, size);
    
    for (size_t i = 0; i < (size_t)power; i++)
    {
        for (size_t b = 0; b < size; b++) 
            for (size_t d = 0; d < size; d++) 
            {
                int sum = 0;
                for (size_t k = 0; k < size; k++) 
                    sum += res_matrix[b][k] * matrix[k][d];
                temp[b][d] = sum;
            }
        for (size_t b = 0; b < size; b++) 
            for (size_t d = 0; d < size; d++) 
                res_matrix[b][d] = temp[b][d];
    }
    free_matrix(temp, size);
}

void mult_matrix(int **matrix_1, int **matrix_2, int **res_matrix, size_t max_size) 
{
    for (size_t i = 0; i < max_size; ++i) 
        for (size_t j = 0; j < max_size; ++j)
        {
            res_matrix[i][j] = 0;
            for (size_t k = 0; k < max_size; ++k) 
                res_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
}
