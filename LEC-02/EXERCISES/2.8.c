#include "stdio.h"

/* rightrot: rotate n bits to the right */
unsigned rightrot(unsigned x, int n)
{
    int i = 0;
    while ((x >> i) != 0)
    {
        i++;
    }
    unsigned x2 = ~(~0 << n) & x;
    printf("x2: %d\n", x2);
    unsigned x1 = x2 << (i - n);
    x2 = x >> n;
    return x1 + x2;
}

int main()
{
    int x = 0b10101101;
    unsigned rightrot_x = rightrot(x, 3);
    printf("newx: %d\n", rightrot_x);
}