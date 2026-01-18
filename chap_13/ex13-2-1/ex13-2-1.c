#include <conio.h>
#include <stdio.h>

int main(void)
{
    clrscr();

    gotoxy(1, 1);
    printf("12345678901234567890 (Ruler)\n");
    printf("----------------------------");
    gotoxy(3, 3);
    printf("LINE1");
    putch('\n');
    printf("LINE2: Line Feed by putch");

    gotoxy(3, 6);
    printf("LINE3");
    putchar('\n');
    printf("LINE4: Line Feed by putchar\n");

    return 0;
}
