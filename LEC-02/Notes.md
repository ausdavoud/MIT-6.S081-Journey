# Lecture 02: GDB and The C Programming Language Book

## Bitwise operations

### Textbook

```c
/* getbits: get n bits from position p */
int getbits(int x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
```
> ~0 means all 1;
Couldn't we replace `~(~0 << n)` with `~(1 << n)`?
Apparently not. Example:
1. 1 << 3 gives: 1000;
2. ~(1 << 3) does not give: 0111; It gives 1111...0111; We're hopeless.
