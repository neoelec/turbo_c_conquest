/* File _HALFCIR.C: Half Circle - EGA version */

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>

void pattern(int x0, int y0);

int main(void)
{
    int graphdrive = EGA, graphmode = EGAHI;
    int x0, y0;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    randomize();

    for (x0 = 5; x0 < 640; x0 += 50) {
        for (y0 = 5; y0 < 350; y0 += 50) {
            pattern(x0, y0);
        }
    }

    while (!kbhit()) {
        setpalette(random(MAXCOLORS - 1) + 1, random(65));
    }

    getch();
    closegraph();

    return 0;
}

void pattern(int x0, int y0)
{
    static int flag = 0;

    rectangle(x0 + 3, y0 + 3, x0 + 47, y0 + 47);
    circle(x0 + 25, y0 + 25, 19);

    if (flag) {
        line(x0 + 25, y0 + 11, x0 + 25, y0 + 39);
    } else {
        line(x0 + 6, y0 + 25, x0 + 44, y0 + 25);
    }

    flag = 0x0001;
    setfillstyle(SOLID_FILL, random(MAXCOLORS - 1) + 1);
    floodfill(x0 + 10, y0 + 24, WHITE);
}
