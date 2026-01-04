/* File CRYSTAL.C: Crystal - HGC/EGA version */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include "turtle.h"

void crystal(double x0, double y0);
void shape(void);

#define SIZE 20.

int main(void)
{
    int graphdrive = DETECT, graphmode;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    initturtle();

    crystal(0., 0.);

    getch();
    closegraph();

    return 0;
}

void crystal(double x0, double y0)
{
    unsigned int i;

    setposition(x0 + SIZE * 2., y0 + SIZE);

    for (i = 0; i < 8; i++) {
        shape();
        turnleft(45.);
        forward(SIZE * 7.);
    }
}

void shape(void)
{
    forward(SIZE * 4.);
    turnright(90.);
    forward(SIZE * 4.);
    turnright(90.);
    forward(SIZE * 2.);
    turnright(90.);
    forward(SIZE * 2.);
    turnright(90.);
    forward(SIZE * 4.);
    turnright(90.);
    forward(SIZE * 1.);
    turnright(90.);
    forward(SIZE * 1.);
    turnright(90.);
    forward(SIZE * 2.);
}
