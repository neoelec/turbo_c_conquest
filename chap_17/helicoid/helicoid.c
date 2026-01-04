/* File HELICOID.C: Helicoid - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>

#define RADIUS 150.

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int x, y, x0, y0;
    double angle;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");

    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2 - 170;

    y = y0 + 40;
    angle = 0.3;
    moveto(x0, y0);

    for (; angle <= 6. * M_PI; angle += M_PI / 25., y += 2, y0 += 2) {
        x = (int)(RADIUS * cos(angle)) + x0;
        lineto(x, y);
        line(x0, y0, x, y);
    }

    getch();
    closegraph();

    return 0;
}
