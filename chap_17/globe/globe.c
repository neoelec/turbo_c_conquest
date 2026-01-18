/* File GLOBE.C: Terrestrial Globe - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>

#include "extgraph.h"

#define LATITUTE 37.29     /*    z|               */
#define LONGITUTE 127.04   /*     |\              */
/* */                      /*     | \             */
#define RADIUS 200.        /*     |  \.           */
#define ZROTATE -LONGITUTE /*     |p /|           */
#define YROTATE -LATITUTE  /*     | / |           */
#define XROTATE 22.5       /*     |/  |           */
#define INTERVAL 15.       /*     +---|------- y  */
/* */                      /*    / \  |           */
int main(void)             /*   / fi\ |           */
{                          /*  x     \|           */
    int graphdrive = DETECT, graphmode;
    int plotted;
    double x, y, z;
    double p, fi;
    double zr, yr, xr;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");

    xr = XROTATE * M_PI / 180.;
    yr = YROTATE * M_PI / 180.;
    zr = ZROTATE * M_PI / 180.;
    circle(getmaxx() / 2, getmaxy() / 2, RADIUS);
    circle(getmaxx() / 2, getmaxy() / 2, 1);

    /* Latitute */
    for (p = M_PI_2; p > -M_PI_2; p -= INTERVAL * M_PI / 180.) {
        plotted = false;

        if (fabs(p - 0.) < 1.e-5) {
            setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        } else {
            setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        }

        for (fi = 0.; fi <= 2. * M_PI; fi += M_PI / 24.) {
            x = RADIUS * cos(p) * cos(fi);
            y = RADIUS * cos(p) * sin(fi);
            z = RADIUS * sin(p);
            rotate3d(xr, yr, zr, &x, &y, &z);

            if (x < 0.) {
                plotted = false;
            } else {
                graph(y, z, &plotted);
            }
        }
    }

    /* Longitute */
    for (fi = 0.; fi < M_PI; fi += INTERVAL * M_PI / 180.) {
        plotted = false;

        if (fi == 0.) {
            setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
        } else {
            setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        }

        for (p = 0.; p <= 2. * M_PI; p += M_PI / 24.) {
            x = RADIUS * cos(p) * cos(fi);
            y = RADIUS * cos(p) * sin(fi);
            z = RADIUS * sin(p);
            rotate3d(xr, yr, zr, &x, &y, &z);

            if (x < 0.) {
                plotted = false;
            } else {
                graph(y, z, &plotted);
            }
        }
    }

    getch();
    closegraph();

    return 0;
}
