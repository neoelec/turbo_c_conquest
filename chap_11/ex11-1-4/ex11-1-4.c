#include <stdio.h>

#define printexprp(expr) printf(#expr " == %p\n", expr)
#define printexpri(expr) printf(#expr " == %d\n", expr)
#define printexprz(expr) printf(#expr " == %u\n", expr)

int main(void)
{
    size_t i, j, k;
    int z[3][2][2];

    i = j = k = 1;

    z[i][j][k] = 100;
    printexprp(z + i);

    printexprz(sizeof(z + i));
    printexprp(*(z + i));
    printexprz(sizeof(*(z + i)));
    printexprz(sizeof(z[i]));
    printexprp(*(z + i) + 0);
    printexprz(sizeof(*(z + i) + 0));

    printexprp(*(z + i) + j);
    printexprz(sizeof(*(z + i) + j));

    printexprp(*(*(z + i) + j));
    printexprz(sizeof(*(*(z + i) + j)));
    printexprz(sizeof(z[i][j]));

    printexprp(*(*(z + i) + j) + k);
    printexprz(sizeof(*(*(z + i) + j) + k));

    printexpri(*(*(*(z + i) + j) + k));
    printexprz(sizeof(*(*(*(z + i) + j) + k)));
    printexprz(sizeof(z[i][j][k]));

    return 0;
}
