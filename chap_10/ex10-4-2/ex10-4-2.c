#include <stdio.h>

#define initpx(i) printf("px == %p\n", px = x + i)
#define printexpr(expr) printf("Operation: " #expr " == %d\n", expr)
#define printpx() printf("After operation... px == %p\n", px)
#define printpx2() printf("                   *px == %d\n\n", *px)

int main(void)
{
    static int x[5] = { 100, 200, 300, 400, 500 };
    int *px;

    initpx(0);
    printexpr(*px++);
    printpx();
    printpx2();
    initpx(0);
    printexpr((*px)++);
    printpx();
    printpx2();

    initpx(3);
    printexpr(*px++);
    printpx();
    printpx2();

    initpx(3);
    printexpr(++(*px));
    printpx();
    printpx2();

    return 0;
}
