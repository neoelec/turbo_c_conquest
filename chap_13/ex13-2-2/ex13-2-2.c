#include <conio.h>
#include <stdio.h>

int main(void)
{
    char c;

    clrscr();

    printf("Test of getch\n");
    printf("---------------\n");
    printf("Input 1: ");
    c = getch();
    printf("\n");
    printf("Result 1: %c\n", c);
    printf("Input 2: ");
    c = getch();
    printf("\n");
    printf("Result 2: %c\n\n", c);

    printf("Test of getche\n");
    printf("---------------\n");
    printf("Input 1: ");
    c = getche();
    printf("\n");
    printf("Result 1: %c\n", c);
    printf("Input 2: ");
    c = getche();
    printf("\n");
    printf("Result 2: %c\n\n", c);

    printf("Test of getchar\n");
    printf("---------------\n");
    printf("Input 1: ");
    c = getchar();
    printf("\n");
    printf("Result 1: %c\n", c);
    printf("Input 2: ");
    c = getchar();
    printf("\n");
    printf("Result 2: %c\n", c);

    return 0;
}
