#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define FUNC_SUCCESS 0

#define OVERFLOW 100
#define OVERLOWED_SIZE 11
#define EMPTY_SIZE 0

#define NO_VALUES 1


int input_array(int *array)
{   
    int element, len = 0, counter = 0;

    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        if (scanf("%d", &element) != 1)
            break;
        
        array[i] = element;
        counter += 1;
        len = counter;
    }

    if (scanf("%d", &element) == 1)
    {
        counter += 1;
        len = counter;

        return len;
    }

    return len;
}


int selection_sort(int *array, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        int min = i;

        for (int j = i + 1; j < len; ++j)
            if (array[j] < array[min])
                min = j;

        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }

    return FUNC_SUCCESS;
}


void print_array(int *array, size_t len)
{
    for (size_t i = 0; i < len; ++i)
        printf("%d ", array[i]);
}


int main(void)
{
    int arr[ARRAY_SIZE];

    size_t size = input_array(arr);
    
    if (size == OVERLOWED_SIZE)
    {
        selection_sort(arr, size - 1);

        print_array(arr, size - 1);

        printf("Overflowed");

        return OVERFLOW;
    }
    if (size == EMPTY_SIZE)
    {
        printf("No values");

        return NO_VALUES;
    }

    selection_sort(arr, size);

    print_array(arr, size);

    return EXIT_SUCCESS;
}

