#include <conio.h>
#include <stdio.h>

#define ESC '\x1b'

void box(int x1, int y1, int x2, int y2);

int main(void)
{
    char c;

    clrscr();

    box(9, 4, 30, 16);
    box(49, 4, 70, 16);

    window(10, 5, 29, 15);
    gotoxy(1, 1);
    puts("BC I/O function test");
    gotoxy(1, 3);
    puts("This line is very long.");
    printf("\n\nThis year is %u. Really ?", 1989);

    window(50, 5, 69, 15);
    gotoxy(1, 1);
    cputs("DC I/O function test");
    gotoxy(1, 3);
    cputs("This line is longer than the width of the active window. \r\n");
    cputs("\r\nEnter any key\r\n(<Esc> to quit)\r\n");

    do {
        if ((c = getche()) == '\r') {
            putch('\n');
        }
    } while (c != ESC);

    return 0;
}

void box(int x1, int y1, int x2, int y2)
{
    int x, y;

    gotoxy(x1, y1);
    putch('\xda');

    for (x = x1 + 1; x < x2; x++) {
        putch('\xc4');
    }

    putch('\xbf');

    for (y = y1 + 1; y < y2; y++) {
        gotoxy(x1, y);
        putch('\xb3');
        gotoxy(x2, y);
        putch('\xb3');
    }

    gotoxy(x1, y2);
    putch('\xc0');

    for (x = x1 + 1; x < x2; x++) {
        putch('\xc4');
    }

    putch('\xd9');
}
