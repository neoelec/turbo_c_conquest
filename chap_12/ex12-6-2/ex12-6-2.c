#include <stdio.h>

#define SMAX 11
#define NMAX 10

void arraycopy(void *dest, void *source, unsigned int size, unsigned int n);

int main(void)
{
    char s1[SMAX] = "Good copy!";
    char s2[SMAX];
    int n1[NMAX] = { 000, 100, 200, 300, 400, 500, 600, 700, 800, 900 };
    int n2[NMAX];
    unsigned int i;

    arraycopy(s2, s1, sizeof(s1[0]), SMAX);
    arraycopy(n2, n1, sizeof(n1[0]), NMAX);

    printf("s1: %s\n", s1);
    printf("s2: %s\nn1: ", s2);

    for (i = 0; i < NMAX; i++) {
        printf("%03d ", n1[i]);
    }

    printf("\nn2: ");

    for (i = 0; i < NMAX; i++) {
        printf("%03d ", n2[i]);
    }

    printf("\n");

    return 0;
}

void arraycopy(void *__dest, void *__source, unsigned int size, unsigned int n)
{
    register unsigned int max;
    char *dest = __dest;
    char *source = __source;

    max = n * size;

    while (max-- > 0) {
        *dest++ = *source++;
    }
}
