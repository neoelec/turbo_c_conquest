/*
 *      File LINESTYL.C
 *      Display a pattern using all of the standard line styles.
 *      HGC/EGA version
 */

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void linestyledemo(void);

int main(void)
{
    int graphdrive = DETECT, graphmode;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    rectangle(0, 0, getmaxx(), getmaxy());
    linestyledemo();
    getch();
    closegraph();

    return 0;
}

void linestyledemo(void)
{
    int style, step;
    int x, y, w, h;
    char str[2];

    w = getmaxx() + 1;
    h = getmaxy() + 1;
    x = 60;
    y = 10;
    step = w / 11;

    settextjustify(CENTER_TEXT, TOP_TEXT);
    outtextxy(x + step * 3 / 2, y, "Normal Width");

    for (style = 0; style < 4; style++, x += step) {
        setlinestyle(style, 0, NORM_WIDTH);
        line(x, y + 20, x, h - 40);
        itoa(style, str, 10);
        outtextxy(x, h - 30, str);
    }

    x += 2 * step;
    outtextxy(x + step * 3 / 2, y, "Thick Width");

    for (style = 0; style < 4; style++, x += step) {
        setlinestyle(style, 0, THICK_WIDTH);
        line(x, y + 20, x, h - 40);
        itoa(style, str, 10);
        outtextxy(x, h - 30, str);
    }
}
