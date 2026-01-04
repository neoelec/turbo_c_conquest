#include <stdio.h>

int main(void)
{
    int x;
    unsigned int y;

    x = -1;
    y = 1;

    if (x < y) {
        printf(" x < y");
    } else {
        printf("x >= y");
    }

    printf("\n");

    return 0;
}
