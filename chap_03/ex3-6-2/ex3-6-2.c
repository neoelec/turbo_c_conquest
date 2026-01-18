#include <stdio.h>

int main(void)
{
    unsigned int year;

    printf("Enter the year of your birthday: ");
    scanf("%u", &year);
    printf("\nYou are %u years old.\n", 1989 - year + 1);

    return 0;
}
