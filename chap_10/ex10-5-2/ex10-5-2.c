#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void bubble(int x[], size_t n);

int main(void)
{
    int x[MAX];
    size_t i;

    randomize();

    for (i = 0; i < MAX; i++) {
        x[i] = random(100);
    }

    printf("\nGenerated array:");

    for (i = 0; i < MAX; i++) {
        printf("%3d", x[i]);
    }

    bubble(x, MAX);
    printf("\nSorted array:   ");

    for (i = 0; i < MAX; i++) {
        printf("%3d", x[i]);
    }

    printf("\n");

    return 0;
}

void bubble(int x[], size_t n)
{
    register size_t i, j;
    int temp;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (x[j - 1] < x[j]) {
                continue;
            }

            temp = x[j - 1];
            x[j - 1] = x[j];
            x[j] = temp;
        }
    }
}
