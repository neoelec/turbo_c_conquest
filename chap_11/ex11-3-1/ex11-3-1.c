#include <stdio.h>

#define ROW 7
#define COL 3

void printdays(char (*days)[COL], size_t row);
void bubblesort(char days[][COL], size_t row);
void swapstr(char s1[], char s2[], size_t col);

int main(void)
{
    char days[ROW][COL] = {
        { 'S', 'U', 'N' }, { 'M', 'O', 'N' }, { 'T', 'U', 'E' },
        { 'W', 'E', 'D' }, { 'T', 'H', 'R' }, { 'F', 'R', 'I' },
        { 'S', 'A', 'T' },
    };

    bubblesort(days, ROW);
    printdays(days, ROW);

    return 0;
}

void printdays(char (*days)[COL], size_t row)
{
    size_t i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", days[i][j]);
        }

        printf("\n");
    }
}

void bubblesort(char days[][COL], size_t row)
{
    register size_t i, j;

    for (i = 0; i < row - 1; i++) {
        for (j = row - 1; j > i; j--) {
            swapstr(days[j - 1], days[j], COL);
        }
    }
}

void swapstr(char s1[], char s2[], size_t col)
{
    register size_t i, temp;

    for (i = 0; i < col; i++) {
        if (s1[i] > s2[i]) {
            break;
        } else if (s1[i] < s2[i]) {
            return;
        }
    }

    if (i == col) {
        return;
    }

    for (i = 0; i < col; i++) {
        temp = s1[i];
        s1[i] = s2[i];
        s2[i] = temp;
    }
}
