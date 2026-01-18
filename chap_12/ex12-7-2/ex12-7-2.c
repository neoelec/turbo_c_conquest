#include <stdio.h>

#define MAX 1024.
#define START 0.
#define END 1.

double f(double x);
double sigma(double (*fp)(double), double a, double b, double delta);

int main(void)
{
    double step;

    for (step = 1.; step <= MAX; step += step) {
        printf("Step:%4lg, Average f == %.14lf\n", step,
               sigma(f, START, END, (END - START) / step) / (step + 1));
    }

    return 0;
}

double f(double x)
{
    return (x * x);
}

double sigma(double (*fp)(double), double a, double b, double delta)
{
    double x = a, sigma = 0.;

    for (; x < b * 1.0000000001; x += delta) {
        sigma += fp(x);
    }

    return sigma;
}
