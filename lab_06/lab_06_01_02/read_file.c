#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include "types_defs.h"
#include "read_file.h"

int size_is_valid(const size_t array_size)
{
    if (array_size == 0) 
        return EMPTY_FILE;
    if (array_size > MAX_SUBJECTS) 
        return OVERFLOW;
	
    return EXIT_SUCCESS;
}

int string_is_valid(char *subject)
{
    subject[strlen(subject) - 1] = '\0';

    if (is_empty_string(subject) == EMPTY_STRING) 
        return EMPTY_STRING;
    if (strlen(subject) >= MAX_LEN) 
        return STRING_LEN_ERROR;

    return EXIT_SUCCESS;
}

int value_is_valid(const double *weight, const double *volume)
{
    if (*weight < 0.0 || *volume < 0.0) 
        return NEGATIVE_VALUE;	
    if (fabs(*volume) < EPS || fabs(*weight) < EPS) 
        return DIVIDE_BY_ZERO;

    return EXIT_SUCCESS;
}

int is_empty_string(const char *const string)
{
    for (size_t i = 0; string[i] != '\0'; i++)
        if (!isspace(string[i]))
            return EXIT_SUCCESS;
    
    return EMPTY_STRING;
}

int read_line(FILE *file, char *subject)
{
    int return_code = 0;

    if (fgets(subject, MAX_LEN, file) == NULL)
        return FILE_END;

    return_code = string_is_valid(subject);
	
    return return_code ? return_code : EXIT_SUCCESS;
}

int read_values(FILE *file, double *weight, double *volume)
{
    int return_code = 0;

    if (fscanf(file, "%lf\n", weight) != 1)
        return FILE_END;
	
    if (fscanf(file, "%lf\n", volume) != 1)
        return FILE_END;

    return_code = value_is_valid(weight, volume);
	
    return return_code ? return_code : EXIT_SUCCESS;
}

int read_file(const char *filename, subject_t *array, size_t *array_size)
{	
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return ERROR_FILE_OPEN;

    int return_code = 0;
    int return_code_file = 0;
    size_t size = 0;
    
    while ((return_code = read_line(file, array[size].subject)) == EXIT_SUCCESS)
    {
        return_code = read_values(file, &array[size].weight, &array[size].volume);		
		
        if (return_code == FILE_END || return_code == NEGATIVE_VALUE || return_code == DIVIDE_BY_ZERO)
        {
            if ((return_code_file = fclose(file)) != 0)
                return return_code_file;
            
            return return_code;
        }
        size++;
    }
    if (return_code == STRING_LEN_ERROR || return_code == EMPTY_STRING)
    {
        if ((return_code_file = fclose(file)) != 0)
            return return_code_file;
        
        return return_code;
    }
    *array_size = size;

    return EXIT_SUCCESS;
}
