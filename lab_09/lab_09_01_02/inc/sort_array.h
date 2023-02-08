#ifndef __SORT_ARRAY_H__
#define __SORT_ARRAY_H__

double comparator(const void *value_1, const void *value_2);
void swap(void *value_1, void *value_2, size_t size);
void mysort(void *array, int element_size, size_t array_size, double (*comparator)(const void*, const void*));

#endif
