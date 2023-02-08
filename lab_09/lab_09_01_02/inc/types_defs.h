#ifndef __FUNCS_H__
#define __FUNCS_H__

#define EPS 1e-7

#define MAX_LEN 26
#define MAX_SUBJECTS 15
#define KEY "ALL"

#define MIN_ARGS 2
#define MAX_ARGS 3

enum errors 
{
    ERROR_FILE_OPEN = 100, 
    FILE_END, 
    EMPTY_FILE,
    ERROR_ARGS,
    NO_MATCHES,
    STRING_LEN_ERROR,
    NEGATIVE_VALUE,
    DIVIDE_BY_ZERO,
    OVERFLOW,
    EMPTY_STRING,
    ERMALLOC,
    ERRLINES
};

enum commands
{
    SORT_ARRAY = 1,
    PRINT_ARRAY, 
    FIND_SUBJECT
};

typedef struct
{
    char *subject;
    double weight;
    double volume;
}subject_t;

#endif
