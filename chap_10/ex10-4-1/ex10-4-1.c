#include <stdio.h>

int main(void)
{
    static int x[5] = { 100, 200, 300, 400, 500 };
    size_t i;
    int *px;

    px = x;
    printf("px = x;     px = %p\n", px);
    px = &x[0];
    printf("px = &x[0]; px = %p\n", px);
    printf("\n\ni    px + i  *(px + i)   px[i]    x[i]\n\n");

    for (i = 0; i <= 4; i++) {
        printf("%u%9p%9d%9d%9d\n\n", i, px + i, *(px + i), px[i], x[i]);
    }

    return 0;
}
