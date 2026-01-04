#include <stdio.h>

int main(void)
{
    size_t i = 1, j = 0;
    int y[2][2] = { { 100, 200 }, { 300, 400 } };

    printf("%d %d %d\n", *(*(y + i) + j), (*(y + i))[j], *(y[i] + j));
    printf("%d %d %d\n", y[i][j], i[y][j], j[i[y]]);
    printf("%d %d %d\n", y[1][0], 1 [y][0], 0 [1 [y]]);

    return 0;
}
