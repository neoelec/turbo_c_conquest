#include <stdio.h>

#define FOREVER 1

int main(void)
{
    char operator;
    int value1, value2;

    do {
        printf("\nEnter expression : ");
        scanf("%i %c %i", &value1, &operator, & value2);
        printf("Result = ");

        switch (operator) {
        case '+':
            if ((value1 == 0) && (value2 == 0)) {
                printf("End");

                return 0;
            } else {
                printf("%d", value1 + value2);
            }

            break;

        case '-':
            printf("%d", value1 - value2);
            break;

        case '*':
            printf("%d", value1 * value2);
            break;

        case '/':
            if (value2 == 0) {
                printf("???\nDivision by zero\n");
            } else {
                printf("%d", value1 / value2);
            }

            break;

        case '%':
            if (value2 == 0) {
                printf("???\nDivision by zero\n");
            } else {
                printf("%d", value1 % value2);
            }

            break;

        case '&':
            printf("%04X", value1 & value2);
            break;

        case '|':
            printf("%04X", value1 | value2);
            break;

        case '^':
            printf("%04X", value1 ^ value2);
            break;

        default:
            printf("Unknown operator\n");

            return 0;
        }
    } while (FOREVER);

    return 0;
}
