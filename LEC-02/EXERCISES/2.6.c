#include "stdio.h"

/* getbits: get n bits from position p */
unsigned getbits(int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* setbits: set n bits of x from position p,
to rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned y_n = y & ~(~0 << n);
    unsigned x_1 = x >> (p + 1) << (p + 1);
    unsigned x_2 = y_n << (p - n + 1);
    unsigned x_3 = ~(~0 << (p - n + 1)) & x;
    unsigned new_x = x_1 + x_2 + x_3;
    return new_x;
}

unsigned setbits2(unsigned x, int p, int n, unsigned y)
{
    unsigned y_n = getbits(y, n - 1, n);
    unsigned x_1 = x >> (p + 1) << (p + 1);
    unsigned x_2 = y_n << (p - n + 1);
    unsigned x_3 = getbits(x, p - n, p - n + 1);
    return x_1 + x_2 + x_3;
}

int main()
{
    int x = 0b10101101;
    int y = 0b11110110;
    unsigned new_x = setbits(x, 5, 4, y);
    printf("newx: %d\n", new_x);
    unsigned new_x2 = setbits2(x, 5, 4, y);
    printf("newx2: %d\n", new_x2);
}