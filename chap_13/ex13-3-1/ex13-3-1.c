#include <stdio.h>

#define GETS_MAX_SIZE 128

int main(void)
{
    char s[GETS_MAX_SIZE];

    do {
        gets(s);
        puts(s);
    } while (*s);

    return 0;
}
