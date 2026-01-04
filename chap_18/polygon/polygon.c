/* File POLYGON.C: Polygons - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include "turtle.h"

#define SIDE 70.
#define MAXVERTEX 18

int main(void)
{
    int graphdrive = DETECT, graphmode;
    unsigned int i, j;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    initturtle();
    drawturtlewindow();

    for (i = 3; i <= MAXVERTEX; i++) {
        setposition(-SIDE / 2., -200.);
        setheading(90.);

        for (j = 0; j < i; j++) {
            forward(SIDE);
            turnleft(360. / (double)i);
        }
    }

    getch();
    closegraph();

    return 0;
}
