/* File CIRCLE.C: Circles - HGC/EGA version */

#include <dos.h>
#include <graphics.h>
#include <math.h>

#define RADIUS 150
#define START 15
#define END 90
#define STEP 15

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int center_x, center_y;
    int xasp, yasp, radius;
    int x0, y0;
    double r;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");

    getaspectratio(&xasp, &yasp);
    center_x = getmaxx() / 2;
    center_y = getmaxy() / 2;

    for (radius = START; radius <= END; radius += STEP) {
        cleardevice();

        for (r = 0.; r < 2. * M_PI; r += M_PI / 8.) {
            x0 = (int)((double)radius * cos(r)) + center_x;
            y0 = (int)((double)radius * sin(r) * xasp / yasp) + center_y;
            circle(x0, y0, RADIUS - radius);
        }

        delay(2000); /* delay 2 sec */
    }

    closegraph();

    return 0;
}
