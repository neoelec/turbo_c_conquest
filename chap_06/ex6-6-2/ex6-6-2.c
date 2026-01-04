#include <stdio.h>

double factorial(int value);

int main(void)
{
    int number;

    printf("Enter integer number : ");
    scanf("%d", &number);
    printf("%d! = %.15lg\n", number, factorial(number));

    return 0;
}

double factorial(int value)
{
    if (value == 0) {
        return 1.;
    } else {
        return ((double)value * factorial(value - 1));
    }
}
