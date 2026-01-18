#include <math.h>
#include <stdio.h>

#define MAXSTEP 100
#define printerror(approx, exact) \
    printf("   Error:%10.6lf%%\n", (approx - exact) / exact * 100.)

double rectangular(double (*fp)(double), double a, double b, unsigned int n);
double trapezoidal(double (*fp)(double), double a, double b, unsigned int n);
double simpson(double (*fp)(double), double a, double b, unsigned int n);

int main(void)
{
    double approx, exact;

    printf("*** f(x) = sin x, [0, pi] ***\n\n");

    printf("Exact value : %.14lf\n", exact = 2.);
    printf("By the Rectangular Rule : %.14lf",
           approx = rectangular(sin, 0., M_PI, MAXSTEP));
    printerror(approx, exact);
    printf("By the Trapezoidal Rule : %.14lf",
           approx = trapezoidal(sin, 0., M_PI, MAXSTEP));
    printerror(approx, exact);
    printf("By the Simpson's Rule   : %.14lf",
           approx = simpson(sin, 0., M_PI, MAXSTEP));
    printerror(approx, exact);

    printf("\n*** f(x) = In x, [1. e] ***\n\n");

    printf("Exact value : *%.14lf\n", exact = 1.);
    printf("By the Rectangular Rule : %.14lf",
           approx = rectangular(log, 1., M_E, MAXSTEP));
    printerror(approx, exact);
    printf("By the Trapezoidal Rule : %.14lf",
           approx = trapezoidal(log, 1., M_E, MAXSTEP));
    printerror(approx, exact);
    printf("By the Simpson's Rule   : %.14lf",
           approx = simpson(log, 1., M_E, MAXSTEP));
    printerror(approx, exact);

    return 0;
}

double rectangular(double (*fp)(double), double a, double b, unsigned int n)
{
    double x, sum = 0., h = (b - a) / n;

    for (x = a + h / 2.; x < b; x += h) {
        sum += fp(x);
    }

    return (h * sum);
}

double trapezoidal(double (*fp)(double), double a, double b, unsigned int n)
{
    double x, sum = 0., h = (b - a) / n;

    for (x = a + h; x < b; x += h) {
        sum += fp(x);
    }

    return (h * (.5 * (fp(a) + fp(b)) + sum));
}

double simpson(double (*fp)(double), double a, double b, unsigned int n)
{
    double x, h = (b - a) / n / 2., s0, s1 = 0., s2 = 0.;

    s0 = fp(a) + fp(b);

    for (x = a + h; x < b; x += 2. * h) {
        s1 += fp(x);
    }

    for (x = a + 2. * h; x < b; x += 2. * h) {
        s2 += fp(x);
    }

    return (h * (s0 + 4. * s1 + 2. * s2) / 3.);
}
