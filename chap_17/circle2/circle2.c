/* File CIRCLE2.C: Circles 2 - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>

#define RRR 120
#define RR (RRR / 2)
#define R 40

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int center_x, center_y;
    int xasp, yasp, i, j;
    double x0, y0, xx0, yy0;
    double radian = M_PI / 180.;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");

    getaspectratio(&xasp, &yasp);
    center_x = getmaxx() / 2;
    center_y = getmaxy() / 2;

    for (i = 0; i < 360; i += 60) {
        x0 = RRR * cos(i * radian) + center_x; /* omit cast oparator */
        y0 = RRR * sin(i * radian) * xasp / yasp + center_y;

        for (j = i + 252; j >= i; j -= 18) {
            xx0 = RR * cos(j * radian) + x0;
            yy0 = RR * sin(j * radian) * xasp / yasp + y0;
            circle(xx0, yy0, R);
        }
    }

    getch();
    closegraph();

    return 0;
}
