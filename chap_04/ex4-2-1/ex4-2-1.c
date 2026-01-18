#include <stdio.h>

int main(void)
{
    int a;

    a = 5;
    a = a * 2 + 10;
    printf("%d, ", a);
    a = 5;
    a *= 2 + 10;
    printf("%d\n", a);

    return 0;
}
