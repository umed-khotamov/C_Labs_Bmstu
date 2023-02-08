#define _POSIX_C_SOURCE 200809L

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

void free_struct(subject_t *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        free(array[i].subject);

    free(array);
}

int string_is_valid(char *subject)
{
    if (is_empty_string(subject) == EMPTY_STRING) 
        return EMPTY_STRING;
    if (strlen(subject) - 1 >= MAX_LEN) 
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

int read_line(FILE *file, char **subject)
{
    int return_code = 0;
    char *temp_subject = NULL;
    size_t len = 0;
 
    if ((return_code = getline(&temp_subject, &len, file)) == -1)
    {
        free(temp_subject);
        
        return return_code;
    }
    return_code = 0;
    *subject = strdup(temp_subject);
    free(temp_subject);

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

int read_file(const char *filename, size_t *array_size)
{	
    subject_t temp;

    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return ERROR_FILE_OPEN;

    int return_code = 0;
    int return_code_file = 0;
    size_t size = 0;

    while ((return_code = read_line(file, &temp.subject)) == EXIT_SUCCESS)
    {
        return_code = read_values(file, &temp.weight, &temp.volume);		
		
        if (return_code == FILE_END || return_code == NEGATIVE_VALUE || return_code == DIVIDE_BY_ZERO)
        {
            if ((return_code_file = fclose(file)) != 0)
                return return_code_file;
            
            free(temp.subject);   
            return return_code;
        }
        size++;
        free(temp.subject); 
    }
    if (return_code == STRING_LEN_ERROR || return_code == EMPTY_STRING)
    {
        if ((return_code_file = fclose(file)) != 0)
            return return_code_file;
        
        free(temp.subject);
        return return_code;
    }
    *array_size = size;

    return EXIT_SUCCESS;
}

int fill_array(const char *filename, subject_t *array, size_t array_size) 
{
    FILE *file = fopen(filename, "r");
    
    if (file == NULL)
        return ERROR_FILE_OPEN;

    for (size_t i = 0; i < array_size; i++)
    {
        read_line(file, &array[i].subject);
        read_values(file, &array[i].weight, &array[i].volume);
    }
    fclose(file);

    return EXIT_SUCCESS;
}
