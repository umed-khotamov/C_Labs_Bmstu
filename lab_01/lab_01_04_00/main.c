#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EMPTY_BOTTLES 20

int main(void)
{    
    int coins;
    scanf("%d", &coins);

    int count = (coins - EMPTY_BOTTLES) / 25;

    printf("%d", count);
     
    return EXIT_SUCCESS;
}
