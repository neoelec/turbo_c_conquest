#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    int i;

    i = 1;
    a = ++i;

    i = 1;
    b = +-i;

    i = 1;
    c = -+i;

    i = 1;
    d = --i;

    printf("%d, %d, %d, %d\n", a, b, c, d);

    return 0;
}
