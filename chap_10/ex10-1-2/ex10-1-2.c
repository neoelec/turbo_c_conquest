#include <stdio.h>

int x[3] = { 1, 2, 0 };

int main(void)
{
    const char *format = "x[%d] = %d, y[%d] = %d, 2[%d] = %d\n";
    size_t i;
    static int y[3] = { 1, 2 };
    static int z[3] = { 1, 2 };

    /* static int a[3] = { 1, 2, 3, 4 }; */

    for (i = 0; i < 3; i++) {
        printf(format, i, x[i], i, y[i], i, z[i]);
    }

    return 0;
}
