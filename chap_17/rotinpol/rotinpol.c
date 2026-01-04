/* File ROTINPOL.C: Rotated Ellipse - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

#include "extgraph.h"

#define ELLIPSEMAX 15
#define POLYGONMAX 8

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int i, x, y, r1, r2, rotateangle;
    static int delta[POLYGONMAX] = { 120, 120, 90, 90, 72, 60, 144, 144 };

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    randomize();

    for (i = 0; i < ELLIPSEMAX; i++) {
        r1 = random(50) + 20;
        r2 = random(50) + 20;
        x = random(getmaxx() - 2 * max(r1, r2)) + max(r1, r2);
        y = random(getmaxy() - 2 * max(r2, r1)) + max(r2, r1);
        rotateangle = random(180);
        rotateangle = random(180);
        rotinpoly(x, y, 0, 720, r1, r2, 15, rotateangle, 1);
        rotinpoly(x, y, 0, 720, r1, r2, delta[random(POLYGONMAX)], rotateangle,
                  1);
    }

    getch();
    closegraph();

    return 0;
}
