#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) 
{         
    double a, b, h;

    scanf("%lf %lf %lf", &a, &b, &h);
    
    double p = a + b + 2 * sqrt(pow(h, 2) + pow((a - b), 2) / 4);
   
    printf("%lf", p);

    return EXIT_SUCCESS;
}
