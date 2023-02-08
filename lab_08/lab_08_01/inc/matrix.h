#ifndef __MATRIX_H__

#define __MATRIX_H__

int **get_copy(int **matrix, size_t rows, size_t cols, int **new_matrix);
void add_row(int **matrix, size_t *rows);
void add_col(int **matrix, size_t rows, size_t *cols);
int del_option(size_t rows, size_t cols);
void del_row(int **matrix, size_t *rows, size_t cols);
void del_col(int **matrix, size_t rows, size_t *cols);
void find_max(int **matrix, size_t rows, size_t cols, size_t *inrow, size_t *incol);   
int fill_matrix(int **matrix, size_t rows, size_t cols);
void print_matrix(int **matrix, size_t rows, size_t cols);
int **alloc_matrix(size_t rows, size_t cols);
void free_matrix(int **matrix, size_t rows);

#endif
