#include <stdio.h>
#include <string.h>

#define MAXMENU 9
#define MAXLENGTH 15

int main(void)
{
    char s[MAXMENU + 1][MAXLENGTH + 1];
    size_t i, sum;

    strcpy(s[1], " [1] Load");
    strcpy(s[2], " [2] Pick");
    strcpy(s[3], " [3] New");
    strcpy(s[4], " [4] Save");
    strcpy(s[5], " [5] Write to");
    strcpy(s[6], " [6] Directory");
    strcpy(s[7], " [7] Change dir");
    strcpy(s[8], " [8] OS shell");
    strcpy(s[9], " [9] Quit");

    for (i = 1; i <= MAXMENU; i++) {
        printf("%s\n", s[i]);
    }

    printf("\nSize of array s: %u bytes.\n\n", sizeof(s));

    for (sum = 0, i = 0; i <= MAXMENU; i++) {
        sum += sizeof(s[i]);
    }

    printf("Two-dimensional array is allocated %u bytes in memory.\n\n", sum);

    for (sum = 0, i = 1; i <= MAXMENU; i++) {
        sum += strlen(s[i]) + 1;
    }

    printf("Total real length of all strings: %u bytes. \n\n", sum);

    printf("Total memory allocated: %u + %u = %u bytes.\n", sizeof(s), sum,
           sum + sizeof(s));

    return 0;
}
