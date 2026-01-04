#include <conio.h>

#define BLANK 0
#define UNDERLINE 1
#define NORMAL 7
#define BOLD 8
#define REVERSE 7

int main(void)
{
    clrscr();

    cputs("\r\n*** Display color attribute ***");
    textattr(BLANK);
    cputs("\r\nl: This line is blank.");
    textattr(NORMAL);
    cputs("\r\n2: This line is normal video.");
    textattr(NORMAL | BOLD);
    cputs("\r\n3: This line is intensified.");
    textattr(UNDERLINE);
    cputs("\r\n4: This line is underlined.");
    textattr(UNDERLINE | BOLD);
    cputs("\r\n5: This line is intensified and underlined.");
    textattr(REVERSE << 4);
    cputs("\r\n6: This line is reverse video.");
    textattr(BLANK | BLINK);
    cputs("\r\nl: This line is blank.");
    textattr(NORMAL | BLINK);
    cputs("\r\n2: This line is blinking normal video.");
    textattr(NORMAL | BOLD | BLINK);
    cputs("\r\n3: This line is blinking intensified.");
    textattr(UNDERLINE | BLINK);
    cputs("\r\n4: This line is blinking underlined.");
    textattr(UNDERLINE | BOLD | BLINK);
    cputs("\r\n5: This line is blinking intensified and underlined.");
    textattr(REVERSE << 4 | BLINK);
    cputs("\r\n6: This line is blinking reverse video.");

    return 0;
}
