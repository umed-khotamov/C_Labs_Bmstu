#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

#define FUNC_SUCCESS 0
#define FUNC_ERROR 1
#define SIZE_INPUT_ERROR 1
#define ARRAY_INPUT_ERROR 1
#define NO_VALUES 1
#define IS_PALINDROME 100
#define NOT_PALINDROME 101
#define PALINDROME_REMOVED 0
#define NO_PALINDROMES 1

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


int value_is_palindrome(int value)
{   
    if (value < 0)
        return NOT_PALINDROME;
    if (value == 0)
        return IS_PALINDROME;

    int reverse = 0, temp = value;
 
    while (value != 0)
    {
        reverse *= 10;
        reverse += value % 10;
        value /= 10;
    }  
    if (temp == reverse)
        return IS_PALINDROME;
    
    return NOT_PALINDROME;
}


void remove_value(int *array, size_t len, size_t index)
{   
    for (size_t i = index + 1; i < len; ++i)
        array[i] = array[i + 1]; 
}



int remove_palindrome(int *array, size_t *len)
{
    int flag = 0;
    size_t size = *len;

    for (size_t i = 0; i < size; ++i)
    {
        if (value_is_palindrome(array[i]) == IS_PALINDROME)
        {   
            flag = 1;
            remove_value(array, --size, --i);
        } 
    }

    *len = size;
    
    if (flag)
        return PALINDROME_REMOVED;
    
    return NO_PALINDROMES;
}


void print_array(int *array, size_t len)
{
    for (size_t i = 0; i < len; ++i)
        printf("%d ", array[i]);
}


int main(void)
{
    int arr[ARRAY_SIZE], n;

    if (scanf("%d", &n) != 1 || n > ARRAY_SIZE || n <= 0)
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
    if (remove_palindrome(arr, &size) == NO_PALINDROMES)
    {
        print_array(arr, size);

        return EXIT_SUCCESS;
    }
    if (size == 0)
    {
        printf("No values");

        return NO_VALUES;
    }

    print_array(arr, size);

    return EXIT_SUCCESS;
}
