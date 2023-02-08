#ifndef __READ_FILE_H__
#define __READ_FILE_H__

int size_is_valid(const size_t array_size);
int string_is_valid(char *const substring);
int value_is_valid(const double *const weight, const double *const volume);
int is_empty_string(const char *const string);
int read_line(FILE *file, char *subject);
int read_values(FILE *file, double *weight, double *volume);
int read_file(const char *filename, subject_t *array, size_t *array_size);

#endif
