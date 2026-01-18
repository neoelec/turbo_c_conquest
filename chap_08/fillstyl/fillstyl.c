/*
 *      File FILLSTYL.C
 *      Display the standard fill patterns(pre-defined fill patterns),
 *      HGC/EGA version
 */

#include <conio.h>
#include <graphics.h>

void fillstyledemo(void);

int main(void)
{
    int graphdrive = DETECT, graphmode;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    rectangle(0, 0, getmaxx(), getmaxy());
    fillstyledemo();
    getch();
    closegraph();

    return 0;
}

void fillstyledemo(void)
{
    char str[3];
    int x, y, h, w, style;
    int i, j;

    w = 2 * ((getmaxx() + 1) / 13);
    h = 2 * ((getmaxy() - 10) / 10);
    x = w / 2;
    y = h / 2;

    for (style = 0, i = 0; i < 3; i++, x = w / 2, y += h / 2 * 3) {
        for (j = 0; j < 4; j++, style++, x += w / 2 * 3) {
            setfillstyle(style, getcolor());
            rectangle(x, y, x + w, y + h);        /* Outline the box         */
            floodfill(x + 1, y + 1, getcolor());  /* Fill box                */
            itoa(style, str, 10);                 /* Convert value to string */
            outtextxy(x + w / 2, y + h + 4, str); /* Output string           */
        }
    }
}
