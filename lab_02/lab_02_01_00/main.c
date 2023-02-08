#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

#define FUNC_SUCCESS 0

#define FUNC_ERROR 1 
#define SIZE_INPUT_ERROR 1
#define ARRAY_INPUT_ERROR 1
#define NO_EVEN_VALUE 1




int input_array(int *array, size_t size)
{
    int element;

    for (size_t i = 0; i < size; ++i)
    {
        if (scanf("%d", &element) != 1)
            return FUNC_ERROR;

        array[i] = element;
    }

    return FUNC_SUCCESS;
}

int even_sum(int *array, int number_of_elements, int *sum)
{   
    int flag = 0;

    for (int i = 0; i < number_of_elements; ++i)
    {   
        if (array[i] % 2 == 0)
        {
            flag = 1;
            *sum += array[i];
        }
    }

    if (flag)
        return FUNC_SUCCESS;

    return NO_EVEN_VALUE;
}


int main(void)
{   
    int arr[ARRAY_SIZE], n, sum = 0; 

    if (scanf("%d", &n) != 1 || n > ARRAY_SIZE || n < 0)
    {
        printf("Input error");
        
        return SIZE_INPUT_ERROR;
    }
    
    size_t size = n;

    if (input_array(arr, size) == FUNC_ERROR)
    {
        printf("Input Error");

        return ARRAY_INPUT_ERROR;
    }

    if (even_sum(arr, size, &sum) == NO_EVEN_VALUE)
    {
        printf("Even numbers don't exist");

        return EXIT_FAILURE;
    }
    printf("%d", sum);

    return EXIT_SUCCESS;
}


