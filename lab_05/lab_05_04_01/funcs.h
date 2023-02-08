#ifndef _FUNCS_H

#define _FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SURNAME_MAX_SIZE 26
#define NAME_MAX_SIZE 11
#define MAX_MARKS 4

#define FILE_OPEN_ERROR 1
#define FILE_WRITE_ERROR 2
#define FILE_READ_ERROR 3
#define FILE_SIZE_ERROR 4
#define NO_MATCHES_FOUND 5
#define SURNAME_SIZE_ERROR 6
#define NAME_SIZE_ERROR 7
#define MARK_ERROR 8
#define MARKS_AMOUNT_ERROR 9
#define ARGUMENT_INPUT_ERROR 53

#define EPS 1e-7


typedef struct 
{
    char surname[SURNAME_MAX_SIZE];
    char name[NAME_MAX_SIZE];
    int mark[MAX_MARKS];
} student_t;


int file_size(FILE *file, size_t *size);
int get_student(FILE *file);
int get_student_by_pos(FILE *file, size_t pos, student_t *value);
void put_student_by_pos(FILE *file, size_t pos, student_t value);
void print_struct(student_t value);
void print_file(FILE *file);
int sort_student(FILE *file);
int find_surname(FILE *file_in, FILE *file_out, char *string);
double get_average(int *array);
double get_overall_average(FILE *file);
void make_new_file(FILE *file, FILE *new_file);
void rewrite_file(FILE *file_in, FILE *file_out);

#endif
