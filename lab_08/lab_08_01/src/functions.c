#include <stdio.h>
#include <stdlib.h>

#include "errs_defs.h"
#include "matrix.h"
#include "matrix_math.h"
#include "functions.h"

int input_size(size_t *rows, size_t *cols)
{
    int temp_rows, temp_cols;

    if ((scanf("%d", &temp_rows)) != 1)
        return ERSINPUT;
    if ((scanf("%d", &temp_cols)) != 1)
        return ERSINPUT;
    
    if (temp_rows < 0 || temp_rows == 0)
        return ERSINPUT;
    if (temp_cols < 0 || temp_cols == 0)
        return ERSINPUT;

    *rows = temp_rows;
    *cols = temp_cols;
    
    return EXIT_SUCCESS;
}

int **create_matrix(size_t *rows, size_t *cols, int *error_code)
{
    int return_code = 0;
    size_t temp_rows = 0;
    size_t temp_cols = 0;

    return_code = input_size(&temp_rows, &temp_cols);

    if (return_code)
    {
        *error_code = return_code;
        return NULL;
    }
    int **matrix = alloc_matrix(temp_rows, temp_cols);
    if (matrix == NULL)
    {
        *error_code = ERMALLOC;
        return NULL;
    }
    return_code = fill_matrix(matrix, temp_rows, temp_cols);
    if (return_code)
    {
        free_matrix(matrix, temp_rows);
        *error_code = return_code;
        return NULL;
    }
    
    *rows = temp_rows;
    *cols = temp_cols;

    return matrix;
}

void get_squared(int **matrix, size_t *rows, size_t *cols)
{
    size_t temp_rows = *rows;
    size_t temp_cols = *cols;

    int option = del_option(temp_rows, temp_cols);

    switch (option)
    {
        case DELROWS:
            while (temp_rows != temp_cols)
                del_row(matrix, &temp_rows, temp_cols);
            break;
        case DELCOLS:
            while (temp_rows != temp_cols)
                del_col(matrix, temp_rows, &temp_cols);
            break;
    }
    *rows = temp_rows;
    *cols = temp_cols;
}

void equate_matrix(int **matrix, size_t *rows, size_t *cols, size_t max_size)
{
    size_t temp_rows = *rows;
    size_t temp_cols = *cols;

    while (temp_rows != max_size)
        add_row(matrix, &temp_rows);

    while (temp_cols != max_size)
        add_col(matrix, temp_rows, &temp_cols);

    *rows = temp_rows;
    *cols = temp_cols;
}

int power_input(int *power_1, int *power_2)
{
    if ((scanf("%d", power_1)) != 1)
        return ERPINPUT;
    
    if ((scanf("%d", power_2)) != 1)
        return ERPINPUT;

    if (*power_1 < 0 || *power_2 < 0)
        return ERPINPUT;

    return EXIT_SUCCESS;
}

int **matrix_operation(int **matrix, int **new_matrix, size_t max_size, int power_1, int power_2)
{
    int **multres_matrix = alloc_matrix(max_size, max_size);
    if (multres_matrix == NULL)
    {
        free_matrix(matrix, max_size);
        free_matrix(new_matrix, max_size);
        return NULL;
    }
    
    int **powres_matrix_1 = alloc_matrix(max_size, max_size);
    if (powres_matrix_1 == NULL)
    {
        free_matrix(matrix, max_size);
        free_matrix(new_matrix, max_size);       
        free_matrix(multres_matrix, max_size);
        return NULL;
    }

    int **powres_matrix_2 = alloc_matrix(max_size, max_size);
    if (powres_matrix_2 == NULL)
    {
        free_matrix(matrix, max_size);
        free_matrix(new_matrix, max_size);
        free_matrix(multres_matrix, max_size);
        free_matrix(powres_matrix_1, max_size);
        
        return NULL;
    }
    identity_matrix(powres_matrix_1, max_size);
    identity_matrix(powres_matrix_2, max_size);
    
    power_matrix(matrix, powres_matrix_1, max_size, power_1);
    power_matrix(new_matrix, powres_matrix_2, max_size, power_2);

    mult_matrix(powres_matrix_1, powres_matrix_2, multres_matrix, max_size);

    free_matrix(powres_matrix_1, max_size);
    free_matrix(powres_matrix_2, max_size);
    free_matrix(matrix, max_size);
    free_matrix(new_matrix, max_size);

    return multres_matrix;
}
