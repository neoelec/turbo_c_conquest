/* File DIARING.C: Diamond Ring - HGC version */

#include <conio.h>
#include <graphics.h>
#include <math.h>

#define SCREEN_XMAX 720
#define SCREEN_YMAX 348
#define CENTER_X (SCREEN_XMAX / 2)
#define CENTER_Y (SCREEN_YMAX / 2)

#define RADIUS 170.
#define VERTEX 18.

int main(void)
{
    int graphdriver = HERCMONO, graphmode = HERCMONOHI;
    unsigned int i, j;
    int x1, y1, x2, y2;
    double pi2 = M_PI * 2.;

    initgraph(&graphdriver, &graphmode, "C:/BORLANDC/BGI");

    for (i = 0; i < VERTEX - 1; i++) {
        x1 = (int)(RADIUS * cos(i * pi2 / VERTEX)) + CENTER_X;
        y1 = (int)(RADIUS * sin(i * pi2 / VERTEX)) + CENTER_Y;

        for (j = i + 1; j < VERTEX; j++) {
            x2 = (int)(RADIUS * cos(j * pi2 / VERTEX)) + CENTER_X;
            y2 = (int)(RADIUS * sin(j * pi2 / VERTEX)) + CENTER_Y;
            line(x1, y1, x2, y2);
        }
    }

    getch();
    closegraph();

    return 0;
}
