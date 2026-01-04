/* File _LISSAJO.C: Lissajous Curve - EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_HEIGHT 350

#define RADIUS (SCREEN_HEIGHT / 10)
#define MAXPATTERNS 9

void lissajous(int x0, int y0, int fx, int fy, int radius, int delta,
               int color);

int main(void)
{
    int graphdrive = EGA, graphmode = EGAHI;
    unsigned int i, j;
    int x0, y0;
    static int ratio[MAXPATTERNS][2] = {
        { 1, 1 }, { 1, 2 }, { 1, 3 }, { 2, 3 }, { 2, 5 },
        { 3, 4 }, { 3, 5 }, { 4, 5 }, { 5, 6 },
    };

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    randomize();

    for (i = 0; i < MAXPATTERNS; i++) {
        for (j = 0; j < 5; j++) {
            x0 = i * RADIUS * 2 + RADIUS;
            y0 = j * RADIUS * 2 + RADIUS;
            lissajous(x0, y0, ratio[i][0], ratio[i][1], RADIUS - 2, 45 * j,
                      random(MAXCOLORS) + 1);
        }
    }

    getch();
    closegraph();

    return 0;
}

void lissajous(int x0, int y0, int fx, int fy, int radius, int delta, int color)
{
    int step;
    int x, y;
    double factor = M_PI / 180.;

    setcolor(color);

    for (step = 0; step <= 360; step += 3) {
        x = radius * cos(fx * step * factor); /* omit cast operator */
        y = radius * cos((fy * step + delta) * factor);

        if (step == 0) {
            moveto(x0 + x, y0 - y);
        } else {
            lineto(x0 + x, y0 - y);
        }
    }
}
