#include <stdio.h>

int main(void)
{
    unsigned int flag;
    unsigned int i;
    double sum, n;

    sum = 0.;
    n = 0.;
    i = 1;

    while (i <= 100) {
        flag = (i % 2 != 0) && (i % 3 != 0);

        if (flag) {
            sum = sum + (double)i;
            n = n + 1.;
        }

        i = i + 1;
    }

    printf("Average = %lf\n", sum / n);

    return 0;
}
