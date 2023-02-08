#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define IN_TRIANGLE 0
#define ON_TRIANGLE 1
#define OUT_OF_TRIANGLE 2

void in_on_out(double k1, double k2, double k3)
{   
    if ((k1 > 0 && k2 > 0 && k3 > 0) || (k1 < 0 && k2 < 0 && k3 < 0))
        printf("%d\n", IN_TRIANGLE);
    else if (((int)k1 == 0 || (int)k2 == 0 || (int)k3 == 0) && ((((int)k1 >= 0 || (int)k2 >= 0 || (int)k3 >= 0) && ((int)k1 <= 0 || (int)k2 <= 0 || (int)k3 <= 0))))
        printf("%d\n", ON_TRIANGLE);
    else
        printf("%d\n", OUT_OF_TRIANGLE);
}

int is_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{   
    double ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double ac = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    double p = (ab + bc + ac) / 2;
    double s = sqrt(p * (p - ac) * (p - bc) * (p - ab));
    double eps = pow(10, -6);    
    if (s < eps)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void point_position(double x1, double y1, double x2, double y2, double x3, double y3, double p1, double p2)
{
    double v1 = (x1 - p1) * (y2 - y1) - (x2 - x1) * (y1 - p2);
    double v2 = (x2 - p1) * (y3 - y2) - (x3 - x2) * (y2 - p2);
    double v3 = (x3 - p1) * (y1 - y3) - (x1 - x3) * (y3 - p2);
    in_on_out(v1, v2, v3);
}

int main(void) 
{
    double a_x, a_y, b_x, b_y, c_x, c_y, k_x, k_y;
    int rc = scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a_x, &a_y, &b_x, &b_y, &c_x, &c_y, &k_x, &k_y);
    
    if (rc != 8 || (is_triangle(a_x, a_y, b_x, b_y, c_x, c_y) == 1))
    {
        printf("Input error");

        return EXIT_FAILURE;
    }

    point_position(a_x, a_y, b_x, b_y, c_x, c_y, k_x, k_y);
    
    return EXIT_SUCCESS;
}   

