#include <stdio.h>

#define MAX 13

int main(void)
{
    size_t i;
    int arr[MAX + 1];

    arr[0] = 2;
    i = 1;

    while (i <= MAX) {
        arr[i] = arr[i - 1] * 2;
        i = i + 1;
    }

    i = 0;

    while (i <= MAX) {
        printf("%d\n", arr[i]);
        i = i + 1;
    }

    return 0;
}
