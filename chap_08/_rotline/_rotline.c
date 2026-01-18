/* File _ROTLINE.C: Rotating Line - EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 350

#define CENTER_X (SCREEN_WIDTH / 2)
#define CENTER_Y (SCREEN_HEIGHT / 2)

#define RADIUS 170.
#define STEP (M_PI / 150.)
#define DEGREE (M_PI / 3. * 2.)

int main(void)
{
    int graphdrive = EGA, graphmode = EGAHI;
    int x1, y1, x2, y2;
    double i, pi = M_PI;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    randomize();

    for (i = 0.; i < 2. * pi; i += STEP) {
        x1 = (int)(RADIUS * cos(i)) + CENTER_X;
        y1 = (int)(RADIUS * sin(i)) + CENTER_Y;
        x2 = (int)(RADIUS * cos(i + DEGREE)) + CENTER_X;
        y2 = (int)(RADIUS * sin(i + DEGREE)) + CENTER_Y;
        setcolor(random(15) + 1);
        line(x1, y1, x2, y2);
    }

    getch();
    closegraph();

    return 0;
}
