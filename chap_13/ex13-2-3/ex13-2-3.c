#include <conio.h>
#include <stdio.h>

int main(void)
{
    unsigned int c;

    clrscr();

    do {
        printf("\nPress any key(or <Return> key to quit): ");

        if ((c = getch()) == 0) {
            c = getch() << 8;
        }

        if (c < 0x100) {
            printf("\nStandard ASCII code -> %#04x", c);
        } else {
            printf("\nExtended key code -> %#06x", c);
        }
    } while (c != '\r');

    return 0;
}
