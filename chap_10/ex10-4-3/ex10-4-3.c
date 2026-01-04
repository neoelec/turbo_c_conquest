#include <conio.h>

void putstr(char *s);

int main(void)
{
    putstr("Happy birthday to you!\nThanks.\n");

    return 0;
}

void putstr(char *s)
{
    while (putch(*s), *s) {
        if (*s++ == '\n') {
            putch('\r');
        }
    }
}
