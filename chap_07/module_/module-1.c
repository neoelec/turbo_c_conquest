/* File MODULE-1.C */

#include <conio.h>
#include <stdio.h>

#include "header.h"

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
