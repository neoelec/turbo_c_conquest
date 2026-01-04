/* File ASPECT.C: Aspect Ratio - HGC/EGA version */

#include <graphics.h>
#include <math.h>

#define RADIUS 100.

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int i, xasp, yasp;
    double x, y, p;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");

    for (i = 0; i <= 600; i += 20) {
        line(i, 0, i, 200);
    }

    for (i = 0; i <= 200; i += 20) {
        line(0, i, 600, i);
    }

    circle(100, 100, (int)RADIUS);

    moveto(200 + RADIUS, 100);

    for (p = 0.; p < 2. * M_PI; p += M_PI / 24.) {
        x = 300 + (int)(RADIUS * cos(p));
        y = 100 - (int)(RADIUS * sin(p));
        lineto(x, y);
    }

    getaspectratio(&xasp, &yasp);
    moveto(200 + RADIUS, 100);

    for (p = 0.; p < 2. * M_PI; p += M_PI / 24.) {
        x = 500 + (int)(RADIUS * cos(p));
        y = 100 - (int)(RADIUS * sin(p) * xasp / yasp);
        lineto(x, y);
    }

    getch();
    closegraph();

    return 0;
}
