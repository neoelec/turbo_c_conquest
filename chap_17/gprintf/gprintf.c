/* File GPRINTF.C: gprintf - HGC/EGA version */

#include <conio.h>
#include <graphics.h>

#include "extgraph.h"

#define SPACE 2

void outlongtext(int space, const char *s);

int main(void)
{
    int graphdrive = DETECT, graphmode;
    int x0, y0, delta;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    drawborder(getmaxcolor());

    x0 = getmaxx() / 2;
    y0 = getmaxy() / 2;

    setviewport(x0 / 3, y0 / 3, x0 + 2 * x0 / 3, y0 + 2 * y0 / 3, 1);
    drawborder(getmaxcolor());

    cpgotoxy(0, 5, SPACE);
    outlongtext(SPACE, "  Ask, and you will receive;\n"
                       "  Seek, and you will find;\n"
                       "  Knock, and the door will be opened to you.\n"
                       "  For everyone who asks will receive, \n"
                       "  and anyone who seeks will find,\n"
                       "  and the door will be opened to him who knocks. \n");
    changetextstyle(GOTHIC_FONT, HORIZ_DIR, 0);
    gprintf(" Matthew %d.%d-%d", 7, 7, 8);

    changetextstyle(TRIPLEX_FONT, HORIZ_DIR, 0);
    cpgotoxy(0, 0, SPACE);
    outtext(" Welcome to my world !");

    inpolygon(50, 200, 90, 810, 28, 28, 144, 1);
    inpolygon(110, 200, 0, 720, 28, 28, 80, 1);
    inpolygon(170, 200, 90, 450, 28, 28, 72, 1);
    inpolygon(350, 180, 0, 2520, 50, 50, 84, 1);

    for (delta = 0; delta < 180; delta += 360 / 8) {
        rotinpoly(245, 190, 0, 360, 20, 40, 12, delta, 1);
    }

    changetextstyle(SMALL_FONT, VERT_DIR, 0);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    gprintfxy(350, 180, "%.1lf", 1989.7);

    getch();
    closegraph();

    return 0;
}

void outlongtext(int space, const char *s)
{
    static char c[2] = "\0";
    const char *ps = s;

    while (*ps) {
        c[0] = *ps++;

        if (c[0] == '\n') {
            newline(space);
        } else {
            outtext(c);
        }
    }
}
