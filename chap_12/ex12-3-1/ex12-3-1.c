#include <stdio.h>

void printmenu(const char *pps[], size_t n);
void printmultimenu(const char *ppss[][2], size_t n);

int main(void)
{
    const char *ps[3];
    const char *pss[3][2];

    ps[0] = "Breakfast";
    ps[1] = "Lunch";
    ps[2] = "Supper";

    pss[0][0] = "Bread";
    pss[0][1] = "Milk";

    pss[1][0] = "Ramyun";
    pss[1][1] = "Kkagdugi";

    pss[2][0] = "Rice";
    pss[2][1] = "Kimchi";

    printmenu(ps, 3);
    printmultimenu(pss, 3);

    return 0;
}

void printmenu(const char *pps[], size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        printf("%-16s", pps[i]);
    }

    printf("\n------------------------------------------\n");
}

void printmultimenu(const char *ppss[][2], size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        printf("%-16s", ppss[i][0]);
    }

    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%-16s", ppss[i][1]);
    }

    printf("\n");
}
