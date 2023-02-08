#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define FUNCTION_ERROR -1
#define EPS 1e-7

double function(double arg)
{
    int rc = 1;
    double func_element, total = 0;

    for (int n = 1; arg >= 0 && rc == 1; ++n)
    {
        func_element = arg / n;
        total += func_element;
        rc = scanf("%lf", &arg);
    }
    if (rc == 1 && arg < 0 && total > 0)
        return sqrt(total);

    return FUNCTION_ERROR;
}

int main(void)
{
    double x;
    
    int rc = scanf("%lf", &x);
    
    if (rc != 1 || x < 0)
    {
        printf("Input error");

        return EXIT_FAILURE;
    }
    double res = function(x);

    if (fabs(res + 1.000000) < EPS)
    {
        printf("Input error");
        
        return EXIT_FAILURE;
    }

    printf("%lf", res);

    return EXIT_SUCCESS;        
}
