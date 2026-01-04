/* File INPOLY.C: Inscribed Polygon - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

#include "extgraph.h"

#define CIRCLEMAX 20
#define POLYGONMAX 9

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int i, x, y, r;
    static int delta[POLYGONMAX] = { 120, 120, 90, 90, 72, 60, 45, 144, 144 };

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    randomize();

    for (i = 0; i < CIRCLEMAX; i++) {
        r = random(50) + 30;
        x = random(getmaxx() - 2 * r) + r;
        y = random(getmaxy() - 2 * r) + r;
        circle(x, y, r);

        inpolygon(x, y, 0, 720, r, r, delta[random(POLYGONMAX)], 1);
    }

    getch();
    closegraph();

    return 0;
}
