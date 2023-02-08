#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define BITS 32

void print_binary(uint32_t number, int n)
{
    n = n % BITS;
    int temp = (int)(pow(2, n) - 1) & number;
    number >>= n;
    number = number | (temp << (BITS - n));

    for (int i = 0; i < BITS; i++)
    {
        uint32_t value = (number >> (BITS - 1 - i)) & 1;
        printf("%u", value);
    }
}

int main(void)
{
    uint32_t a;
    int shift;
    if (scanf("%u%d", &a, &shift) != 2 || shift < 0)
    {
        printf("Error: input error");
        
        return EXIT_FAILURE;
    }
    printf("Result: ");
    print_binary(a, shift);
    
    return EXIT_SUCCESS;    
}
