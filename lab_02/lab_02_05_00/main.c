#include <stdio.h>
#include <stdlib.h>


#define ARRAY_SIZE 10
#define FUNC_SUCCESS 0
#define FUNC_ERROR 1
#define SIZE_INPUT_ERROR 1
#define ARRAY_INPUT_ERROR 1 


int input_array(int *pa, int *pb)
{
    int element;

    for (; pa < pb; ++pa)
    {
        if (scanf("%d", &element) != 1)
            return FUNC_ERROR;
    
        *pa = element;
    }
    
    return FUNC_SUCCESS;
}


int max_value(int *pa, int *pb)
{
    int i = 2, total = 0;    
    int max = *pa + *(pb - 1);

    for (pa += 1; pa < pb; ++pa)
    {
        total = *pa + *(pb - i);
        i += 1;
        if (total > max)
            max = total;
    }
    
    return max;
}


int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n <= 1 || n > ARRAY_SIZE)
    {
        printf("Input error");

        return SIZE_INPUT_ERROR;
    }
    
    int arr[ARRAY_SIZE], *pb;
    int *pa = arr;
    size_t size = n;

    pb = pa + size;

    if (input_array(pa, pb) == FUNC_ERROR)
    {
        printf("Input error");

        return ARRAY_INPUT_ERROR;
    }

    int res = max_value(pa, pb);

    printf("%d\n", res);

    return EXIT_SUCCESS;
}
