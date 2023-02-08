#ifndef __MATH_MATRIX_H__

#define __MATH_MATRIX_H__

void identity_matrix(int **matrix, size_t size);
void power_matrix(int **matrix, int **res_matrix, size_t size, int power);
void mult_matrix(int **matrix_1, int **matrix_2, int **res_matrix, size_t max_size);
int **matrix_operation(int **new_matrix_1, int **new_matrix_2, size_t max_size, int power_1, int power_2);

#endif
