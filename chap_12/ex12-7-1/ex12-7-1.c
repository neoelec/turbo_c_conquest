#include <math.h>
#include <stdio.h>

#define printexprf(expr) printf("%11s == %.14lf\n", #expr, expr)

int main(void)
{
    double (*fp)(double);

    fp = log10;
    printexprf(log10(2.));
    printexprf(log10  (2.));
    printexprf((*fp)(2.));
    printexprf(fp(2.));
    printexprf(fp(2.));

    return 0;
}
