#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LEFT_BORDER -1
#define RIGHT_BORDER 1
#define EPS 1e-7

double row_arcsin_sum(double x, double eps)
{
    double sum = x;
    long n = 1;
    double t = pow(x, 3) / 6.0;

    while (eps < fabs(t))
    {
        sum += t;
        n += 1;
        t *= ((2 * n) - 1) * ((2 * n) - 1) * x * x;
        t /= 2 * n * ((2 * n) + 1);
    }
    return sum;
}


int main(void)
{
    double x, eps;
    int rc = scanf("%lf%lf", &x, &eps);
    
    if ((rc != 2) || (x < LEFT_BORDER) || (x > RIGHT_BORDER) || (eps > 1) || (eps < 0))
    {
        printf("Error");

        return EXIT_FAILURE;
    }
    double res_s = row_arcsin_sum(x, eps);
    printf("%lf\n", res_s);

    double res_f = asin(x);
    printf("%lf\n", res_f);

    double abs_er, rel_er;

    abs_er = res_f - res_s;

    if (fabs(res_f) < EPS)
        rel_er = 0;
    else
        rel_er = abs_er / res_f;

    printf("%lf\n", fabs(abs_er));
    printf("%lf\n", fabs(rel_er));
    
    return EXIT_SUCCESS;
}   


