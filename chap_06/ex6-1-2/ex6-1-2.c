#include <stdio.h>

int power(int n, int m)
{
    int i, result = 1;

    for (i = 1; i <= m; i++) {
        result *= n;
    }

    return result;
}

int main(void)
{
    int i;

    for (i = 0; i <= 14; i++) {
        printf("%5d\n", power(2, i));
    }

    return 0;
}
