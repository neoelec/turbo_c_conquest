#include <conio.h>
#include <stdio.h>

int main(void)
{
    size_t i;
    float x;
    double y;

    x = 0.;
    y = 0.;

    for (i = 0; i < 10000; i++) {
        x = y + 100000.;
        y = y + 100000.;
    }

    printf("%.6e\n", x / 10000.);
    printf("%.6le\n", y / 10000.);

    while (!kbhit()) {
    }

    return 0;
}
