#include "stdio.h"

/* invert: invert n bits from position p */
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ~(~0 << n) << (p - n + 1);
    return x ^ mask;
}

int main()
{
    int x = 0b10101101;
    unsigned invert_x = invert(x, 5, 4);
    printf("newx: %d\n", invert_x);
}