#include <math.h>
#include <stdio.h>

int main(void)
{
    double pi, y;

    printf("2.               = %.14lf\n", 2.);
    printf("2.00000000000000 = %.14lf\n", 2.00000000000000);

    pi = asin(1.) * 2.;
    printf("\npi = %.14lf\n\n", pi);

    y = sin(pi / 6.);
    printf(" sin(pi / 6) = %.14lf\n", y);

    pi = 3.141592;
    y = sin(pi / 6.);
    printf(" sin(3.141592 / 6) = %.14lf\n", y);

    return 0;
}
