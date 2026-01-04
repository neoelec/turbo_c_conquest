#include <stdio.h>
#include <string.h>

int main(void)
{
    static char days[8][4];
    static char *months[13];
    size_t i;

    strcpy(days[1], "SUN");
    strcpy(days[2], "MON");
    strcpy(days[3], "TUE");
    strcpy(days[4], "WED");
    strcpy(days[5], "THU");
    strcpy(days[6], "FRI");
    strcpy(days[7], "SAT");

    months[1] = "January";
    months[2] = "February";
    months[3] = "March";
    months[4] = "April";
    months[5] = "May";
    months[6] = "June";
    months[7] = "July";
    months[8] = "August";
    months[9] = "September";
    months[10] = "October";
    months[11] = "November";
    months[12] = "December";

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
