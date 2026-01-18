#include <conio.h>
#include <stdio.h>

int main(void)
{
    clrscr();

    printf("|%d|\n", 626);
    printf("|%6d|\n", 626);
    printf("|%06d|\n", 626);
    printf("|%-6d|\n", 626);
    printf("|%-06d|\n", 626);
    printf("\n");

    printf("|%x|\n", 729);
    printf("|%6x|\n", 729);
    printf("|%06x|\n", 729);
    printf("|%-6x|\n", 729);
    printf("|%-06x|\n", 729);
    printf("\n");

    printf("|%10ld|\n", 626L);
    printf("|%10ld|\n", 7291968);
    printf("|%10d|\n", -1);
    printf("|%10u|\n", -1);

    return 0;
}
