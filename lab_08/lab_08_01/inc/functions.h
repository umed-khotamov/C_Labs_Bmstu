#ifndef __FUNCTIONS_H__

#define __FUNCTIONC_H__

int input_size(size_t *rows, size_t *cols);
void get_squared(int **matrix, size_t *rows, size_t *cols);
int power_input(int *power_1, int *power_2);
int **matrix_operation(int **new_matrix_1, int **new_matrix_2, size_t max_size, int power_1, int power_2);
void equate_matrix(int **matrix, size_t *rows, size_t *cols, size_t max_size);
int **create_matrix(size_t *rows, size_t *cols, int *error_code);

#endif
