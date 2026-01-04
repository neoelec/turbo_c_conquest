#include <stdio.h>

int main(void)
{
    int exitcode;

    printf("Enter exit code(0 - 255): ");
    scanf("%d", &exitcode);

    return exitcode;
}
