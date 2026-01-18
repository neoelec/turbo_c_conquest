#include <stdio.h>

int main(void)
{
    int l, m, n;
    float x;
    double xx;

    printf("\nEnter one decimal integer: ");
    scanf("%d", &n);
    printf("\nNumber: %d\n", n);

    printf("\nEnter three any integer: ");
    scanf("%i %i %i", &l, &m, &n);
    printf("\nNumber: %d, %#o, %#x\n", l, m, n);

    printf("\nEnter one single precision floating point number: ");
    scanf("%f", &x);
    printf("\nNumber: %.7g\n", x);

    printf("\nEnter one double precision floating point number: ");
    scanf("%lf", &xx);
    printf("\nNumber: %.15lg\n", xx);

    printf("\n");

    return 0;
}
