#include <stdio.h>

int main(void)
{
    char c, d;

    c = 'A';
    d = 0xa0;

    if (c < d) {
        printf("'A' < 0xa0");
    } else {
        printf("'A' >= 0xa0");
    }

    printf("\n");

    return 0;
}
