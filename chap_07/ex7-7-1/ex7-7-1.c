#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 46

#define VIEW                                \
    do {                                    \
        unsigned int _temp = 0;             \
                                            \
        printf("[i:%2d]: ", i);             \
        for (; _temp <= i; _temp++) {       \
            cprintf("%10lu", array[_temp]); \
            if (_temp % 7 == 6)             \
                printf("\n        ");       \
        }                                   \
        printf("\n");                       \
    } while (0)

unsigned long fibonacci(unsigned int n);

unsigned long array[MAXARRAY];

int main(void)
{
    unsigned int i;
    unsigned long sum = 0UL;

    for (i = 0; i < MAXARRAY; i++) {
        array[i] = fibonacci(i);
        VIEW;

        if (kbhit()) {
            exit(EXIT_SUCCESS);
        }
    }

    for (i = 0; i < MAXARRAY; i++) {
        sum += array[i];
    }

    printf("======================================\n");
    printf("Sum of fibonacci 0 ... %u: %lu\n", MAXARRAY - 1, sum);
    printf("======================================\n");

    printf("\n");
    i--;
    VIEW;

    return 0;
}

unsigned long fibonacci(unsigned int n)
{
    unsigned long cur, prepre = 0UL, pre = 1UL;

    if (n <= 1) {
        return n;
    }

    while (--n > 0) {
        cur = prepre + pre;
        prepre = pre;
        pre = cur;
    }

    return cur;
}
