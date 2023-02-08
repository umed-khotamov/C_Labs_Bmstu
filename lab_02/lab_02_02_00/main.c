#include <stdio.h>
#include <stdlib.h>

#define N 10

#define FUNC_SUCCESS 0
#define FUNC_ERROR 1

#define SIZE_INPUT_ERROR 1
#define ARRAY_INPUT_ERROR 1
#define IS_AVERAGE 100
#define NO_AVERAGE -100

int input_array(int *array, size_t len)
{
    int element;

    for (size_t i = 0; i < len; ++i)
    {
        if (scanf("%d", &element) != 1)
            return FUNC_ERROR;
        
        array[i] = element;
    }
    
    return FUNC_SUCCESS;
}


double average(int *array, size_t len)
{
    int sum = 0, counter = 0;

    for (size_t i = 0; i < len; ++i)
        if (array[i] != 0)
        {   
            counter += 1;
            sum += array[i];
        }
    double average_value = (double)sum / counter;

    return average_value;
}


int make_new_array(int *array, int *new_arr, double average_value, size_t len, size_t *new_len)
{   
    int flag = 0;
    
    for (size_t i = 0; i < len; ++i)
    {
        if ((double)array[i] > average_value)
        {
            flag = 1;
            new_arr[*new_len] = array[i];
            *new_len = *new_len + 1;
        }
    }

    if (flag)
        return IS_AVERAGE;

    return NO_AVERAGE;
}

void print_new_array(int *new_arr, int len)
{
    for (size_t i = 0; i < len; ++i)
        printf("%d ", new_arr[i]);
}

int main(void)
{
    int arr[N], new_arr[N], n;

    if (scanf("%d", &n) != 1 || n > N || n < 0)
    {
        printf("Input error");

        return SIZE_INPUT_ERROR;
    }

    size_t size = n;

    if (input_array(arr, size) == FUNC_ERROR)
    {
        printf("Input error");

        return ARRAY_INPUT_ERROR;
    }

    double average_value = average(arr, size);
    
    size_t new_size = 0;

    if (make_new_array(arr, new_arr, average_value, size, &new_size) == IS_AVERAGE)
    {
        print_new_array(new_arr, new_size);

        return EXIT_SUCCESS;
    }
    
    return EXIT_FAILURE;
}
