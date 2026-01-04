#include <stdio.h>

int main(void)
{
    double x, y;

    x = exp(1);
    y = exp(1.);
    printf("%lf, %lf\n", x, y);

    return 0;
}
