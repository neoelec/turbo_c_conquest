#include <stdio.h>

#define printexpre(expr) printf("%16s == %c\n", #expr, expr)
#define printexprs(expr) printf("%16s == \"%s\"\n", #expr, expr)
#define printexpri(expr) printf("%16s == %d\n", #expr, expr)

int main(void)
{
    void *pv;
    char *ps, s[] = "ABCDEFG";
    int *px, x[] = { 1234, 2345, 3456 };

    ps = s;
    px = x;

    pv = ps;
    printexprs(ps);

    printexprs((char *)pv);
    printexpre(*ps);
    printexpre(*(char *)pv);
    pv = ps + 1;
    ps = pv;
    printexprs((char *)pv);
    printexprs(ps);

    pv = px;
    printexpri(*px);
    printexpri(*(int *)pv);
    printexpri(*(px + 1));
    printexpri(*((int *)pv + 1));
    printexpri(px[2]);
    printexpri(((int *)pv)[2]);

    return 0;
}
