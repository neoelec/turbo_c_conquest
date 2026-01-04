#include <conio.h>

#define MAXLENGTH 12

int main(void)
{
    char s[MAXLENGTH + 3], *ps;

    s[0] = MAXLENGTH + 1;

    do {
        ps = cgets(s);
        cprintf("\r\ns[1] = %hhd: %s\r\n", s[1], ps);
    } while (*ps);

    return 0;
}
