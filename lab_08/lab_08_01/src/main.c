#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errs_defs.h"
#include "matrix.h"
#include "functions.h"
#include "matrix_math.h"

int main(void)
{
    int return_code = 0;
    
    size_t rows_1 = 0, rows_2 = 0;
    size_t cols_1 = 0, cols_2 = 0;
    
    int **matrix_1 = create_matrix(&rows_1, &cols_1, &return_code);
    if (return_code)
        return return_code;

    int **matrix_2 = create_matrix(&rows_2, &cols_2, &return_code);
    if (return_code)
    {
        free_matrix(matrix_1, rows_1);
        return return_code;
    }
    size_t prev_size_1 = rows_1;
    size_t prev_size_2 = rows_2;

    get_squared(matrix_1, &rows_1, &cols_1);
    get_squared(matrix_2, &rows_2, &cols_2);
    
    size_t max_size = (rows_1 > rows_2) ? rows_1 : rows_2;
    
    int **new_matrix_1 = alloc_matrix(max_size, max_size);
    if (new_matrix_1 == NULL)
    {
        free_matrix(matrix_1, prev_size_1);
        free_matrix(matrix_2, prev_size_2);

        return ERMALLOC;
    }
    get_copy(matrix_1, rows_1, cols_1, new_matrix_1);

    int **new_matrix_2 = alloc_matrix(max_size, max_size);
    if (new_matrix_2 == NULL)
    {
        free_matrix(matrix_1, prev_size_1);
        free_matrix(matrix_2, prev_size_2);
        free_matrix(new_matrix_1, max_size);
        
        return ERMALLOC;
    }
    get_copy(matrix_2, rows_2, cols_2, new_matrix_2);
    
    free_matrix(matrix_1, prev_size_1);
    free_matrix(matrix_2, prev_size_2);

    if (rows_1 < rows_2)
        equate_matrix(new_matrix_1, &rows_1, &cols_1, rows_2);
    else
        equate_matrix(new_matrix_2, &rows_2, &cols_2, rows_1);

    int pow_1, pow_2;

    if ((return_code = power_input(&pow_1, &pow_2)) != EXIT_SUCCESS)
    {
        free_matrix(new_matrix_1, max_size);
        free_matrix(new_matrix_2, max_size);

        return return_code;
    }
    int **multres_matrix = matrix_operation(new_matrix_1, new_matrix_2, max_size, pow_1, pow_2);
    if (multres_matrix == NULL)
        return ERMALLOC;

    print_matrix(multres_matrix, max_size, max_size);
 
    free_matrix(multres_matrix, max_size);
    
    return EXIT_SUCCESS;
}
