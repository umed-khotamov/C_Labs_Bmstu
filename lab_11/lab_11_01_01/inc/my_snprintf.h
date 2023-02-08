#ifndef MY_SNPRINTF_H

#define MY_SNPRINTF_H

#include <stdlib.h>

char *convert(int num, int base);
int my_snprintf(char *str, size_t size, char *format, ...);

#endif
