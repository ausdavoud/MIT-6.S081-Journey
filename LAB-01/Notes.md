# Lab 1: Utils

## How does Atoi work?

```c
int
Atoi(const char *s) {
    int n;

    while ('0' <= *s && *s <= '9')
        n = 10 * n + *s++ - '0';
    return n;
}
```

First of all, HOLY MOTHER OF COW! That's so genius!

Imagine s is "25". Then here's how it works:
1. `*s` is the first digit of s, `'2'`. It checks if it's a number between 0 and 9. In fact, it checks wether the ascii of `'2'` is between ascii of `'0'` and `'9'`. If we reach the end of `s`, `*s` will return ascii `NUL` (in the ascii table, `NUL` is `0`, `'0'` is `48` and `'9'` is `57`).
2. Next, it multiplies the current n (which is 0 for now) by `10`, then adds it to `*s` which is `2` (ignore `++` for now). 
But here's the catch. `*s` returns `'2'` which is a char. So when it's added to a number (10*n), the compiler converts `'2'` to a number implicitly. `'2'` is `50` in ascii table. That's why we subtract `'0'` from the result, to even out this `50` thing. In fact, The ascii for `'0'` is `48`, so subtracting it from `50` will leave us `2`. 
\
What is `++` for? It moves cursor to the next character in `s`. We could do it in the next line but that's how it's done.