#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INTO_METERS 100

int main(void)
{   
    double height, chest_girth, weight;

    scanf("%lf %lf %lf", &height, &chest_girth, &weight);
    
    double normal_weight = (height * chest_girth) / 240;
    double height_meters = height / INTO_METERS;
    double weight_index = weight / (pow(height_meters, 2));

    printf("%lf\n", normal_weight);
    printf("%lf\n", weight_index);

    return EXIT_SUCCESS;
} 
