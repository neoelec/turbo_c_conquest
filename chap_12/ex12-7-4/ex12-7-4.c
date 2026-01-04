#include <stdio.h>

#define printexpr(expr, s, segs) \
    printf(#expr " == %Fp, %s segment == %04X\n", expr, #s, segs)

int a;

void f(void)
{
}

int main(void)
{
    static int b;
    int c;
    void far *pv;

    pv = &a;
    printexpr(pv, Data, _DS);

    pv = &b;
    printexpr(pv, Data, _DS);

    pv = &c;
    printexpr(pv, Data, _DS);

    pv = f;
    printexpr(pv, Code, _CS);

    return 0;
}
