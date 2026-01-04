#include <stdio.h>

int main(void)
{
    printf("%8lg\n", 3.141592);
    printf("%8lg\n", 1.23456789e5);
    printf("%8lg\n", 1.23456789e6);
    printf("%8lg\n", 1.23456789e-4);
    printf("%8lg\n", 1.23456789e-5);
    printf("%8lg\n", 471.0000);
    printf("%8lg\n", 471.0000e5);
    printf("%8lg\n", 471.0000e-3);

    return 0;
}
