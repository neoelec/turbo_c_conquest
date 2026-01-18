#include <conio.h>
#include <stdlib.h>
#include <string.h>

void displaystr(const char *s, size_t len)
{
    cputs("dest = ");

    for (putch('"'); len-- > 0; s++) {
        if (*s == '\0') {
            cputs("\\0");
        } else {
            putch(*s);
        }
    }

    cputs("\"\r\n");
}

int main(void)
{
    char *src, dest[10];

    clrscr();
    memset(dest, '%', 10);
    strcpy(dest, "ABC");
    displaystr(dest, 10);
    src = "DEFGHIJ";
    strncat(dest, src, 5);
    displaystr(dest, 10);

    cputs("\r\n");

    memset(dest, '%', 10);
    strcpy(dest, "ABC");
    displaystr(dest, 10);
    src = "DE";
    strncat(dest, src, 5);
    displaystr(dest, 10);

    return 0;
}
