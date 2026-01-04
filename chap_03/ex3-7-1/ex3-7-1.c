#include <conio.h>
#include <stdio.h>
#include <string.h>

#define MAXLENGTH 10

int main(void)
{
    char s[MAXLENGTH + 3];

    s[0] = MAXLENGTH + 1;
    printf("Enter a string: ");
    cgets(s);

    printf("\nString length by s[1] = %hhd\n", s[1]);

    printf("String length by strlen = %u\n", strlen(s + 2));
    printf("String: %s\n", s + 2);

    return 0;
}
