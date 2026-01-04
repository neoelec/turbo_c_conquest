#include <stdio.h>

int main(void)
{
    size_t i;
    int x[3] = { 100, 200, 300 };

    for (i = 0; i < 3; i++) {
        printf("%d ", x[i]);
    }

    for (i = 0; i < 3; i++) {
        printf("%d ", i[x]);
    }

    for (i = 1; i <= 3; i++) {
        printf("%d ", (i - 1)[x]);
    }

    printf("\n");

    return 0;
}
