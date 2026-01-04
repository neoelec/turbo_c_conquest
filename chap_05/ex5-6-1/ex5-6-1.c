#include <stdio.h>

int main(void)
{
    unsigned int i;

    for (i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            continue;
        }

        printf("%4u", i);
    }

    printf("\n");

    return 0;
}
