#include <dos.h>
#include <stdio.h>

#define MAXINT 32767

double timeused(struct time *tm2, struct time *tm1);
int _n, _m;

#define LOOP(i, j)                 \
    for (i = 0; i < MAXINT; i++) { \
        for (j = 0; j < 10; j++) { \
        }                          \
    }

int main(void)
{
    register int i, j;
    int n, m;
    static int a, b;
    long nn, mm;
    double regtime;
    struct time start, end;

    /* Test of register variable */

    gettime(&start);
    LOOP(i, j);
    gettime(&end);
    regtime = timeused(&end, &start);
    printf("Int type register variable: %.1lf%%.\a\n",
           timeused(&end, &start) / regtime * 100.);

    /* Test of automatic variable */

    gettime(&start);
    LOOP(n, m);
    gettime(&end);
    printf("Int type automatic variable: %.1lf%%.\a\n",
           timeused(&end, &start) / regtime * 100.);

    /* Test of external variable */

    gettime(&start);
    LOOP(_n, _m);
    gettime(&end);
    printf("Int type external variable: %.1lf%%.\a\n",
           timeused(&end, &start) / regtime * 100.);

    /* Test of static variable */

    gettime(&start);
    LOOP(a, b);
    gettime(&end);
    printf("Int type static variable: %.1lf%%.\a\n",
           timeused(&end, &start) / regtime * 100.);

    /* Test of automatic variable of long type */

    gettime(&start);
    LOOP(nn, mm);
    gettime(&end);
    printf("Long type automatic variable: %.1lf%%.\a\n",
           timeused(&end, &start) / regtime * 100.);

    return 0;
}

double timeused(struct time *tm2, struct time *tm1)
{
    return ((tm2->ti_min - tm1->ti_min) * 60. + tm2->ti_sec - tm1->ti_sec +
            (tm2->ti_hund - tm1->ti_hund) / 100.);
}
