/* File FANTAGON.C: Fantagon - HGC/EGA version */

#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include "turtle.h"

/* Shape control */
int countmax[] = {
    6, 6, 6, 8, 8, 8, 8, 10, 10, 10, 12, 16,
};
int extra_cnt[] = {
    5, 3, 1, 9, 7, 5, 1, 7, 5, 3, 1, 3,
};
/* Center adjusting */
double side[] = {
    40., 35., 25., 35., 35., 30., 30., 30., 20., 25., 25., 25.,
};
double xstart[] = {
    -20., -46., -66., -81., -46., -39., 24., 9., -26., 20., 20., -33.,
};
double ystart[] = {
    -28., 15., -90., 63., -15., -54., -8., 13., 9., 28., 29., 11.,
};
int cntstart[] = {
    6, 4, 6, 8, 8, 6, 0, 10, 8, 2, 2, 4,
};

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int i, j, k;
    int extrarot, count;
    double angle;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    initturtle();

    for (i = 0; i < 12; i++) {
        clearscreen();
        dot(0., 0.);
        setposition(xstart[i], ystart[i]);
        setheading(90.);
        extrarot = 1;
        count = cntstart[i];
        angle = 72.;

        for (j = 0; j < countmax[i] * 5; j++) {
            if (++count > countmax[i]) {
                extrarot = -extra_cnt[i];
                count = 1;
            }

            if (++extrarot > 2) {
                extrarot = 1;
            }

            for (k = 0; k < 5 + extrarot; k++) {
                forward(side[i]);
                turnleft(angle);
            }

            forward(side[i]);
            turnleft(angle *= -1.);
        }

        delay(2000); /* delay 2 sec */
    }

    closegraph();

    return 0;
}

/* Other shapes */

/* countmax :   18  20  20  20  22  24 */
/* extracnt :    9   3  15  19   7  23 */
/* cntstart :   18  20  20  20   22 24 */
/* side = 10.~20. */
/* xstart, ystart : some value(may be hard to calculate) */
/* countmax must be even(>=6). */
/* extra_cnt must be odd(>=1). */
/* cntstart must be even(>=0. <=countmax) */
