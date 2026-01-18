/* File SOMBRERO.C: Sombrero - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>

#include "extgraph.h"

/* */               /*     |z       */
#define SIZE 2.     /*     |        */
#define ZROTATE 11. /*     |        */
#define YROTATE 40. /*     +------y */
#define XROTATE 0.  /*    /         */
                    /*   /          */
                    /*  x           */

double function(double x, double y)
{
    double f;

    f = hypot(x, y) / 35.;

    if (fabs(f) < 1.e-5) {
        return (40. * M_PI);
    } else {
        return (40. * sin(f * M_PI) / f);
    }
}

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int plotted = false;
    double x, y, z, x2, y2, z2;
    double zr, yr, xr;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    zr = ZROTATE * M_PI / 180.;
    yr = YROTATE * M_PI / 180.;
    xr = XROTATE * M_PI / 180.;

    for (x = -115.; x <= 115.; x += 5.) {
        for (y = -115.; y <= 115.; y += 5.) {
            z = function(x, y);
            x2 = x * SIZE;
            y2 = y * SIZE;
            z2 = z * SIZE;
            rotate3d(xr, yr, zr, &x2, &y2, &z2);
            graph(y2, z2, &plotted);
        }

        plotted = false;
    }

    getch();
    closegraph();

    return 0;
}
