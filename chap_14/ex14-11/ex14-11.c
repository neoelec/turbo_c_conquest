#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Don't tell me no lies.";

    puts(s);
    puts(strupr(s));
    puts(strlwr(s));
    strnset(s + 2, ' ', 3);
    puts(s);
    puts(strset(s, '%'));

    return 0;
}
