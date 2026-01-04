/* File KOCHCURV.C: Koch Curve - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include "turtle.h"

#define NEST 4     /* NEST = 5     */
#define DIST 4.    /* DIST = 2. =  */
#define XCOL -160. /* XCOL = -250. */
#define YCOL 0.    /* YCOL = 0.    */

void koch(unsigned int n, double dist);

int main(void)
{
    int graphdrive = DETECT, graphmode;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    initturtle();
    drawturtlewindow();

    setheading(90.);
    setposition(XCOL, YCOL);
    koch(NEST, DIST);

    getch();
    closegraph();

    return 0;
}

void koch(unsigned int n, double dist)
{
    if (n == 0) {
        forward(dist); /* initialization */
    } else {
        koch(n - 1, dist); /* recursive call */
        turnleft(60.);
        koch(n - 1, dist);
        turnleft(-120.);
        koch(n - 1, dist);
        turnleft(60.);
        koch(n - 1, dist);
    }
}
