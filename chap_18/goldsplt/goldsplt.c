/* File GOLDSTLT.C: Golden Split - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include "turtle.h"

#define DIST 450.

int main(void)
{
    int graphdrive = DETECT, graphmode;
    unsigned int i;
    double angle, dist = DIST, dx, dy;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    initturtle();

    angle = deg(atan(M_SQRT2)); /* angle == 54.73561 */
    setposition(DIST * (_cos(angle) + -sin(angle) * M_SQRT_2) / 2.,
                -DIST * _sin(angle) / 2.);

    setheading(-90. + angle);

    for (i = 1; i < 13; i++) {
        forward(dist);
        dx = dist * _cos(angle);
        dy = dist * _sin(angle);
        turnleft(90. + angle);
        forward(dy);
        turnleft(90.);
        forward(dx);
        turnleft(90.);
        forward(dy);
        turnleft(90.);
        forward(dx);
        turnleft(90. - angle);
        dist /= M_SQRT2;
    }

    getch();
    closegraph();

    return 0;
}
