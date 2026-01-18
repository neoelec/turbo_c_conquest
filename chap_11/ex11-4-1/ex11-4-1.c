#include <stdio.h>

#define SIZE 3

void plus(int *pml, int *pm2, int *result, size_t row, size_t col);

int main(void)
{
    int matrix1[][SIZE] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
    };
    int matrix2[][SIZE] = {
        { 9, 8, 7 },
        { 3, 2, 1 },
        { 6, 5, 4 },
    };
    int result[SIZE][SIZE];
    size_t i, j;

    plus((int *)matrix1, (int *)matrix2, (int *)result, SIZE, SIZE);

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%3d", result[i][j]);
        }

        printf("\n");
    }

    return 0;
}

#define matrix(name, r, c) (*(name + r * col + c))

void plus(int *pml, int *pm2, int *result, size_t row, size_t col)
{
    size_t i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrix(result, i, j) = matrix(pml, i, j) + matrix(pm2, i, j);
        }
    }
}
