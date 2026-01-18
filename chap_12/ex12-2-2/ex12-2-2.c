#include <stdio.h>

int main(void)
{
    char *ps[3], **pps;
    size_t i;

    pps = ps;

    pps[0] = "Breakfast\n";
    pps[1] = "Lunch\n";
    pps[2] = "Supper\n";

    for (i = 0; i < 3; i++) {
        printf(pps[i]);
    }

    return 0;
}
