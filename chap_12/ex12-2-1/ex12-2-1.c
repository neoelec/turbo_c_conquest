#include <stdio.h>

#define printexpri(expr) printf("%-5s == %4hhd\n", #expr, expr)
#define printexprp(expr) printf("%-5s == %4p\n", #expr, expr)

int main(void)
{
    char a, *pa, **ppa;

    a = 3;
    pa = &a;
    ppa = &pa;

    printexpri(a);
    printexpri(*pa);
    printexpri(**ppa);

    printexprp(&a);
    printexprp(pa);
    printexprp(*ppa);

    printexprp(&pa);
    printexprp(ppa);

    return 0;
}
