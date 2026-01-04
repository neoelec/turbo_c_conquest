#include <conio.h>
#include <stdio.h>

int main(void)
{
    double x = 68.0330;
    double y = -68.0330;

    clrscr();

    printf("|%lf|\n", x);
    printf("|%15.7lf|\n", x);
    printf("|%-15.7lf|\n", x);
    printf("|%015.7lf|\n", x);
    printf("|%-015.7lf|\n", x);

    printf("\n");

    printf("|%lf|\n", y);
    printf("|%15.7lf|\n", y);
    printf("|%-15.7lf|\n", y);
    printf("|%015.7lf|\n", y);
    printf("|%-015.7lf|\n", y);

    printf("\n");

    printf("|%le|\n", x);
    printf("|%15.7le|\n", x);
    printf("|%-15.7le|\n", x);
    printf("|%015.7le|\n", x);
    printf("|%-015.7le|\n", x);

    printf("\n");

    printf("|%lg|\n", x);
    printf("|%15.7lg|\n", x);
    printf("|%-15.7lg|\n", x);
    printf("|%015.7lg|\n", x);
    printf("|%-015.7lg|\n", x);

    return 0;
}
