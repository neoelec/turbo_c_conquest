#include <conio.h>
#include <string.h>

#define sign(n) putch(((n) == 0) ? '0' : ((n) > 0) ? '+' : '-')

void compare_string(const char *s1, const char *s2)
{
    cprintf("%-10s%-10s  ", s1, s2);
    sign(strcmp(s1, s2));
    cputs("         ");
    sign(stricmp(s1, s2));
    cputs("\r\n");
}

int main(void)
{
    clrscr();

    cputs("  s1        s2      strcmp   stricmp\r\n");
    cputs("--------------------------------------\r\n");

    compare_string("Equal", "Equal");
    compare_string("LYK", "Lyk");
    compare_string("Lee M.H.", "LEE M.H.");
    compare_string("12345", "12344");
    compare_string("ABCDE", "ABCDd");
    compare_string("ABC", "ABCD");
    compare_string("ABCD", "ABC");
    compare_string("", "Null!");
    compare_string("ABCD", "aBCD");
    compare_string("ABCD", "AbCD");
    compare_string("ABCD", "ABcD");

    return 0;
}
