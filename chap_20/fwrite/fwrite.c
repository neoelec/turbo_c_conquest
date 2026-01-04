/* File FWRITE.C */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

double array[SIZE];

int fcmp(const void *__px, const void *__py);

int main(void)
{
    unsigned int i;
    FILE *stream;

    randomize();

    for (i = 0; i < SIZE; i++) {
        array[i] = (double)random(1000) / random(1000);
    }

    printf("\nGenerated random number\n\n");

    for (i = 0; i < SIZE; i++) {
        printf("%10.6lf\n", array[i]);
    }

    qsort(array, SIZE, sizeof(double), fcmp);

    if ((stream = fopen("fwrite.out", "w+b")) == NULL) {
        exit(EXIT_FAILURE);
    }

    if (fwrite(array, sizeof(double), SIZE, stream) != SIZE) {
        exit(EXIT_FAILURE);
    }

    rewind(stream);
    printf("\nSorted random number\n\n");

    for (i = 0; i < SIZE; i++) {
        if (fread(&array[i], sizeof(double), 1, stream) != 1) {
            exit(EXIT_FAILURE);
        }

        printf("%10.6lf\n", array[i]);
    }

    return 0;
}

int fcmp(const void *__px, const void *__py)
{
    const double *px = __px;
    const double *py = __py;

    return ((*px < *py) ? -1 : (*px > *py) ? 1 : 0);
}
