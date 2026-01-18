#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double round(double x);

int main(void)
{
    char *dfm = "%-17s == %17.14lf\n";
    char *ifm = "%-17s == %17d\n";
    char *lfm = "%-17s == %17ld\n";
    double pi;

    clrscr();
    pi = acos(-1.0);
    printf(dfm, "pi", pi);

    printf("\n");
    printf(dfm, "sin(pi / 3.0)", sin(pi / 3.0));
    printf(dfm, "cos(pi / 6.0)", cos(pi / 6.0));
    printf(dfm, "tan(pi / 3.0)", tan(pi / 3.0));

    printf("\n");
    printf(dfm, "pow(3.0, 0.5)", pow(3.0, 0.5));
    printf(dfm, "sqrt(3.0)", sqrt(3.0));
    printf(dfm, "pow10(-10)", pow10(-10));
    printf(dfm, "exp(1.0)", exp(1.0));
    printf(dfm, "hypot(3.0, 4.0)", hypot(3.0, 4.0));

    printf("\n");
    printf(dfm, "log(2.0)", log(2.0));
    printf(dfm, "log(exp(1.0))", log(exp(1.0)));
    printf(dfm, "log10(2.0)", log10(2.0));
    printf(dfm, "log10(10.0)", log10(10.0));

    printf("\n");
    printf(dfm, "pi / 2.0", pi / 2.0);
    printf(dfm, "asin(1.0)", asin(1.0));
    printf(dfm, "acos(0.0)", acos(0.0));
    printf(dfm, "atan(1.0)", atan(1.0));
    printf(dfm, "atan2(1.0, 1.0)", atan2(1.0, 1.0));
    printf(dfm, "atan(pi / 1.0e-5)", atan(pi / 1.0e-5));
    printf(dfm, "atan2(pi, 1.0e-5)", atan2(pi, 1.0e-5));

    printf("\n");
    printf(dfm, "sinh(1.0)", sinh(1.0));
    printf(dfm, "cosh(1.0)", cosh(1.0));
    printf(dfm, "tanh(1.0)", tanh(1.0));

    printf("\n");
    printf(ifm, "abs(-1)", abs(-1));
    printf(lfm, "labs(-65536)", labs(-65536L));
    printf(dfm, "fabs(-pi)", fabs(-pi));

    printf("\n");
    printf(ifm, "max(1, 2)", max(1, 2));
    printf(lfm, "max(65536, 1L)", max(65536L, 1L));
    printf(dfm, "max(1.0, 2.0)", max(1.0, 2.0));
    printf(ifm, "min(1, 2)", min(1, 2));
    printf(dfm, "min(1.0, 2.0)", min(1.0, 2.0));
    printf("\n");
    printf(dfm, "floor(1.2)", floor(1.2));
    printf(dfm, "floor(-1.2)", floor(-1.2));
    printf(dfm, "ceil(1.2)", ceil(1.2));
    printf(dfm, "ceil(-1.2)", ceil(-1.2));
    printf(dfm, "(double)(int)1.2", (double)(int)1.2);
    printf(dfm, "(double)(int)-1.2", (double)(int)-1.2);
    printf(dfm, "round(1.2)", round(1.2));
    printf(dfm, "round(-1.2)", round(-1.2));
    printf(dfm, "round(1.5)", round(1.5));
    printf(dfm, "round(-1.5)", round(-1.5));

    printf("\n");
    printf(dfm, "floor(-1.5 + 0.5)", floor(-1.5 + 0.5));
    printf(dfm, "(double)(int)(-1.5 + 0.5)", (double)(int)(-1.5 + 0.5));

    return 0;
}

double round(double x)
{
    return ((x > 0) ? floor(x + .5) : ceil(x - .5));
}
