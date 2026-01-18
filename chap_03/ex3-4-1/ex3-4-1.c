#include <conio.h>
#include <stdio.h>
#include <string.h>

#define STRINGLEN 21

int main(void)
{
    char chararray[STRINGLEN + 1];
    char *str;

    clrscr();

    strcpy(chararray, "Welcome to my world !");
    str = chararray;

    printf("%s\n", chararray);
    printf("%s\n", str);

    printf("String length of str:       %u\n", strlen(str));
    printf("String length of chararray: %u\n", strlen(chararray));
    printf("str[0]: '%c'\n", str[0]);

    printf("str[12] '%c', chararray[12] '%c'\n", str[12], chararray[12]);
    printf("End of str: %hhu\n", str[strlen(str)]);

    return 0;
}
