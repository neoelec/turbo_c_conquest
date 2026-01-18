#include <stdio.h>

#define printexpr(expr) printf(#expr " == %.1lf\n", expr)

double sum(double x[], size_t n);
double sum2(double x[], size_t n);

int main(void)
{
    double x[] = { 1., 2., 3., 4., 5., 6., 7., 8., 9., 10. };

    printexpr(sum(x, sizeof(x) / sizeof(double)));
    printexpr(sum2(x, sizeof(x) / sizeof(double)));
    printexpr(sum(x, 5));

    printexpr(sum(x + 5, 5));
    printexpr(sum(&x[5], 5));

    return 0;
}

double sum(double *px, size_t n)
{
    double sum = 0.;

    while (n-- > 0) {
        sum += *px++;
    }

    return sum;
}

double sum2(double px[], size_t n)
{
    size_t i;
    double sum = 0.;

    for (i = 0; i < n; i++) {
        sum += px[i];
    }

    return sum;
}
