#include <stdio.h>

#define printexprp(expr) printf(#expr " == %p\n", expr)
#define printexpri(expr) printf(#expr " == %d\n", expr)
#define printexprz(expr) printf(#expr " == %u\n", expr)

int main(void)
{
    int y[][2] = { { 100, 200 }, { 300, 400 }, { 500, 600 } };

    int(*py)[2];

    py = y;

    printexprp(y[1]);
    printexprp(py[1]);
    printexprz(sizeof(y[0]));
    printexprz(sizeof(py[0]));
    printexpri(y[0][0]);
    printexpri(py[0][0]);
    printexpri(y[2][1]);
    printexpri(py[2][1]);

    return 0;
}
