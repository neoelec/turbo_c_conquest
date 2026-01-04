/* File O_SPIRAL.C: Spiral Circle - HGC version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 348
#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)
#define MAXPATTERNS 12

#define A 5.
#define C .0015
#define MAXDEGREE 2800
#define K 4.

double _cos(int degree);
double _sin(int degree);

int main(void)
{
    int graphdrive = HERCMONO, graphmode = HERCMONOHI;
    int i, x, y;
    double r;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    randomize();

    for (i = 0; i <= MAXDEGREE; i += 30) {
        r = A * exp(C * (double)i);
        x = (int)(r * -cos(i)) + CENTER_X;
        y = (int)(r * -sin(i)) + CENTER_Y;
        circle(x, y, (int)(r / K));
        setfillstyle(random(MAXPATTERNS - 2) + 2, 1);
        floodfill(x, y, 1);
    }

    getch();
    closegraph();

    return 0;
}

double _cos(int degree)
{
    return cos((double)degree * M_PI / 180.);
}

double _sin(int degree)
{
    return sin((double)degree * M_PI / 180.);
}
