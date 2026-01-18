#include <stdio.h>

int main(void)
{
    int array[] = { 1, 2, 3, 4, 5 };

    printf("\nint variable occupies %u bytes in memory.\n", sizeof(int));
    printf("\narray[] occupies %u bytes in memory.\n\n", sizeof(array));
    printf("Hence array[] has %u elements.\n", sizeof(array) / sizeof(int));

    return 0;
}
