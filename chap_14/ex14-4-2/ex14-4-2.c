#include <conio.h>

#define BAR_WIDTH 8
#define BAR_LENGTH 9

void colorbar(int x0, int y0, char c);

int main(void)
{
    int i, x;

    clrscr();
    highvideo();
    gotoxy(33, 1);
    cputs("<< Color Demo >>");

    for (x = 5, i = 0; x < 80; x += 10, i++) {
        gotoxy(x, 3);
        cprintf("%2d", i);
        gotoxy(x, 14);
        cprintf("%2d", i + 8);
    }

    for (x = 2, i = 0; x < 80; x += 10, i++) {
        textbackground(i);
        colorbar(x, 4, ' ');
    }

    for (x = 2, i = 8; x < 80; x += 10, i++) {
        textcolor(i);
        colorbar(x, 15, '\xdb');
    }

    while (!kbhit()) {
    }

    return 0;
}

void colorbar(int x0, int y0, char c)
{
    int x, y;

    for (y = y0; y < y0 + BAR_LENGTH; y++) {
        gotoxy(x0, y);

        for (x = x0; x < x0 + BAR_WIDTH; x++) {
            putch(c);
        }
    }
}
