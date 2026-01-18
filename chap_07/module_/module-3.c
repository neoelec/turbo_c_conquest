/* File MODULE-3.C */

#include <stdio.h>

#include "header.h"

static int count(void);

void printcount(void)
{
    printf("I am Module III.\n");
    printf("Count: %d\n\n", count());
}

static int count(void)
{
    static int number = 0;

    return ++number;
}
