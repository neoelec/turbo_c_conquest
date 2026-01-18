#include <conio.h>
#include <stdio.h>

int main(void)
{
    char c, s[100], *format;
    int n, array[100];
    float x;
    double xx;

    clrscr();
    format = "%u\n";
    printf(format, sizeof(-1));         /* 2                    */
    printf(format, sizeof(0xff));       /* 2, int type          */
    printf(format, sizeof(0xffff));     /* 2, unsigned int type */
    printf(format, sizeof(65535));      /* 4, long type         */
    printf(format, sizeof(32767));      /* 2, int type          */
    printf(format, sizeof(c));          /* 1                    */
    printf(format, sizeof(s));          /* 100 * 1 = 100        */
    printf(format, sizeof(n));          /* 2                    */
    printf(format, sizeof(array));      /* 100 * 2 = 200        */
    printf(format, sizeof(x));          /* 4                    */
    printf(format, sizeof(xx));         /* 8                    */
    printf(format, sizeof(format));     /* 2, near pointer      */
    printf(format, sizeof(char));       /* 1                    */
    printf(format, sizeof(int));        /* 2                    */
    printf(format, sizeof(long));       /* 4                    */
    printf(format, sizeof(float));      /* 4                    */
    printf(format, sizeof(double));     /* 8                    */
    printf(format, sizeof(char *));     /* 2, near pointer      */
    printf(format, sizeof(int *));      /* 2, near pointer      */
    printf(format, sizeof(float *));    /* 2, near pointer      */
    printf(format, sizeof(double *));   /* 2, near pointer      */
    printf(format, sizeof(char far *)); /* 4, far pointer       */
    printf(format, sizeof(1 + 1.));     /* 8                    */
    printf(format, sizeof(1 + 1L));     /* 4, long type         */
    printf(format, sizeof('\n\t'));     /* 2, int type          */
    printf(format, sizeof('\0'));       /* 2, int type          */

    return 0;
}
