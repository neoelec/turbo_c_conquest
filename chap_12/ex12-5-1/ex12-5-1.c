#include <stdio.h>

int main(void)
{
    static char days[][4] = {
        "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT",
    };
    static char *months[] = {
        NULL,      "January",  "February", "March",  "April",
        "May",     "June",     "July",     "August", "September",
        "October", "November", "December",
    };
    size_t i;

    for (i = 1; i <= 7; i++) {
        printf("%-4s", days[i]);
    }

    printf("\n");

    for (i = 1; i <= 12; i++) {
        printf("%-10s", months[i]);
    }

    printf("\n");

    return 0;
}
