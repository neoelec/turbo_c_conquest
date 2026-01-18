#include <stdio.h>
#include <string.h>

#define MAXMENU 9

int main(void)
{
    char *ps[MAXMENU + 1];
    size_t i, sum;

    ps[1] = " [1] Load";
    ps[2] = " [2] Pick";
    ps[3] = " [3] New";
    ps[4] = " [4] Save";
    ps[5] = " [5] Write to";
    ps[6] = " [6] Directory";
    ps[7] = " [7] Change dir";
    ps[8] = " [8] OS shell";
    ps[9] = " [9] Quit";

    for (i = 1; i <= MAXMENU; i++) {
        printf("%s\n", ps[i]);
    }

    printf("\nSize of pointer array ps: %u bytes.\n\n", sizeof(ps));

    for (sum = 0, i = 1; i <= MAXMENU; i++) {
        sum += strlen(ps[i]) + 1;
    }

    printf("Total real length of all strings: %u bytes.\n\n", sum);
    printf("Total memory allocated: %u + %u = %u bytes\n", sizeof(ps), sum,
           sizeof(ps) + sum);

    return 0;
}
