#include <conio.h>
#include <stdio.h>

int main(void)
{
    int i = 32;

    clrscr();

    while (i < 127) {
        printf("%c ", i);

        if (i % 32 == 31) {
            printf("\n");
        }

        i = i + 1;
    }

    return 0;
}
