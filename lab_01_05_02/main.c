#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX_VALUE 46

int factorial(int fi_1, int fi_2, int value)
{
    for (int i = 2; i <= value; i++)
    {
        int total = fi_1 + fi_2;
        fi_1 = fi_2;
        fi_2 = total;
    }

    return fi_2;
}


int main(void)
{
    int n, a = 0, b = 1;

    int rc = scanf("%d", &n);
    
    if (rc != 1 || n > MAX_VALUE || n < 0)
    {
        printf("Input error");

        return EXIT_FAILURE;
    }
    if (n == 0)
        printf("%d", a);
    else
        printf("%d", factorial(a, b, n));

    return EXIT_SUCCESS;
}
