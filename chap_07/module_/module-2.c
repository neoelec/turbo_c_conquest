/* File MODULE-2.C */

#include <stdio.h>
#include <string.h>

#include "header.h"

static void reverse(char *s);
static void swapchar(char *c, char *d);

void printmessage(void)
{
    printf("\n\nI am Module II.\n");
    reverse(message);
    printf("Your message: %s\n", message);
}

static void reverse(char *s)
{
    size_t i, j, len;

    len = strlen(s);

    for (i = 0, j = len - 1; i < j && len != 0; i++, j--) {
        swapchar(&s[i], &s[j]);
    }
}

static void swapchar(char *c, char *d)
{
    char temp;

    temp = *c;
    *c = *d;
    *d = temp;
}
