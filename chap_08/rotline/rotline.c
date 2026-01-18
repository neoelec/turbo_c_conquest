/* File ROTLINE.C: Rotating Line - HGC version */

#include <conio.h>
#include <graphics.h>
#include <math.h>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 348

#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

#define RADIUS 170.
#define STEP (M_PI / 80.)
#define DEGREE (M_PI / 3. * 2.)

int main(void)
{
    int graphdrive = HERCMONO, graphmode = HERCMONOHI;
    int x1, y1, x2, y2;
    double i, pi = M_PI;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");

    for (i = 0.; i < 2. * pi; i += STEP) {
        x1 = (int)(RADIUS * cos(i)) + CENTER_X;
        y1 = (int)(RADIUS * sin(i)) + CENTER_Y;
        x2 = (int)(RADIUS * cos(i + DEGREE)) + CENTER_X;
        y2 = (int)(RADIUS * sin(i + DEGREE)) + CENTER_Y;
        line(x1, y1, x2, y2);
    }

    getch();
    closegraph();

    return 0;
}
