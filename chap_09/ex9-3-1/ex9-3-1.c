#include <math.h>
#include <stdio.h>

#define printexpr(expr) printf(#expr " = %d\n", expr)
#define printexpr2(expr) printf(#expr " = %lf\n", expr)
#define x_n(x, n) (x##n)

int main(void)
{
    int x1, x2, x3;

    printexpr(1 + 1);
    printexpr(3 * 6);
    printexpr(4 / 3);
    printexpr2(exp(1.));
    printexpr2(log10(2.));
    printexpr2(acos(-1.));
    printexpr2(asin(1.));
    printexpr2(hypot(3., 4.));

    x_n(x, 1) = 100;
    x_n(x, 2) = 200;
    x_n(x, 3) = 300;
    printf("%d, %d, %d\n", x1, x2, x3);

    return 0;
}
