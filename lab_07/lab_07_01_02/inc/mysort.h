#ifndef __MY_SORT_H__
#define __MY_SORT_H__

int key(int *start, int *end, int **new_array_start, int **new_array_end);
int compare_int(const void *value_1, const void *value_2);
int swap(void *value_1, void *value_2, size_t size);
int mysort(void *array, size_t count, size_t size, int (*compare_int)(const void*, const void*));
void command_sort(const char *filename, int *start, int *end, size_t size, int (*compare_int)(const void*, const void*));

#endif
