/* File ROTSQUAR.C: Rotating Square - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include "turtle.h"

#define ANGLE 89.
#define STEP 2

#define MAX 250

int main(void)
{
    int graphdrive = DETECT, graphmode;
    unsigned int i;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    initturtle();

    for (i = 5; i < MAX; i += STEP) {
        forward((double)i);
        turnleft(ANGLE);
    }

    getch();
    closegraph();

    return 0;
}
