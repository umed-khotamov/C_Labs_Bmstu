#ifndef __IO_FILE_H__
#define __IO_FILE_H__

int get_file_size(const char *filename, size_t *size);
int fill_array(const char *filename, int **array, size_t temp_size);
void write_to_file(const char *filename, int *start, int *end);
int init_array(const char *filename, int **array, size_t *size);

#endif
