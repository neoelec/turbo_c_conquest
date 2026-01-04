#include <stdio.h>

#define printexprp(expr) printf(#expr " == %p\n", expr)
#define printexpri(expr) printf(#expr " == %d\n", expr)
#define printexprz(expr) printf(#expr " == %u\n", expr)

int main(void)
{
    int x[2], *px;
    int y[2][2], (*py)[2];

    px = x;
    px = &x[0];
    py = y;
    py = &y[0];

    printexprp(px);
    printexprp(x);
    printexprp(&x[0]);

    printexprp(py);
    printexprp(y);
    printexprp(&y[0]);

    printexprp(y[0]);
    printexprp(&y[0][0]);

    printexprz(sizeof(*px));
    printexprz(sizeof(*x));
    printexprz(sizeof(*&x[0]));

    printexprz(sizeof(*py));
    printexprz(sizeof(*y));
    printexprz(sizeof(*&y[0]));

    printexprz(sizeof(*y[0]));
    printexprz(sizeof(*&y[0][0]));

    return 0;
}
