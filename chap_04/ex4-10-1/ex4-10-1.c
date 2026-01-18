#include <stdio.h>

int main(void)
{
    int x, y;

    x = (y = 0, y + 5);
    printf("x = %d  y = %d\n", x, y);

    return 0;
}
