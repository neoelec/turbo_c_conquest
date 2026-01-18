/* File MODULE.C */

#include <conio.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 70

void printmessage(void);
void swapchar(char *c, char *d);
void reverse(char *s);
void printcount(void);
int count(void);

char *message;

int main(void)
{
    char buffer[MAXLENGTH + 3];

    buffer[0] = MAXLENGTH + 1;
    message = buffer + 2;

    do {
        printf("I am Module I, The Main Module. \n");
        printf("Enter message: ");
        cgets(buffer);
        printmessage();
        printcount();
    } while (buffer[1] != 0);

    return 0;
}

void printmessage(void)
{
    printf("\n\nI am Module II.\n");
    reverse(message);
    printf("Your message: %s\n", message);
}

void reverse(char *s)
{
    size_t i, j, len;

    len = strlen(s);

    for (i = 0, j = len - 1; i < j && len != 0; i++, j--) {
        swapchar(&s[i], &s[j]);
    }
}

void swapchar(char *c, char *d)
{
    char temp;

    temp = *c;
    *c = *d;
    *d = temp;
}

void printcount(void)
{
    printf("I am Module III.\n");
    printf("Count: %d\n\n", count());
}

int count(void)
{
    static int number = 0;

    return ++number;
}
