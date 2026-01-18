#include <conio.h>
#include <stdio.h>

int main(void)
{
    char *string;

    clrscr();

    string = "'100% IBM compatible' is the top of the lies.";

    printf("|%s|\n", string);
    printf("|%60s|\n", string);
    printf("|%-60s|\n", string);
    printf("|%30.21s|\n", string);
    printf("|%-30.21s|\n", string);
    printf("|%30.30s|\n", string);

    return 0;
}
