/*
 *      File FILLPATT.C
 *      Demonstrate ho to use the user definable fill patterns.
 *      HGC/EGA version
 */

#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

void fillpatterndemo(void);

int main(void)
{
    int graphdrive = DETECT, graphmode;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    rectangle(0, 0, getmaxx(), getmaxy());
    fillpatterndemo();
    getch();
    closegraph();

    return 0;
}

void fillpatterndemo(void)
{
    char str[3];
    int x, y, h, w, style;
    int i, j;
    static char patterns[][8] = {
        /* User-defined 12 fill patterns */
        { 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55 },
        { 0x33, 0x33, 0xec, 0xec, 0x33, 0x33, 0xcc, 0xce },
        { 0xf0, 0xf0, 0xf0, 0xf0, 0x0f, 0x0f, 0x0f, 0x0f },
        { 0x00, 0x10, 0x28, 0x44, 0x28, 0x10, 0x00, 0x00 },
        { 0x00, 0x70, 0x20, 0x27, 0x24, 0x24, 0x07, 0x00 },
        { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 },
        { 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00 },
        { 0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x00 },
        { 0x00, 0x00, 0x22, 0x08, 0x00, 0x22, 0x1c, 0x00 },
        { 0xff, 0x7e, 0x3c, 0x18, 0x18, 0x3c, 0x7e, 0xff },
        { 0x00, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x00 },
        { 0x00, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x00 },
    };

    w = 2 * ((getmaxx() + 1) / 13);
    h = 2 * ((getmaxy() - 10) / 10);
    x = w / 2;
    y = h / 2;

    for (style = 0, i = 0; i < 3; i++, x = w / 2, y += h / 2 * 3) {
        for (j = 0; j < 4; j++, style++, x += w / 2 * 3) {
            setfillpattern(patterns[style], getcolor());
            rectangle(x, y, x + w, y + h);        /* Outline the box         */
            floodfill(x + 1, y + 1, getcolor());  /* Fill box                */
            itoa(style, str, 10);                 /* Convert value to string */
            outtextxy(x + w / 2, y + h + 4, str); /* Output string           */
        }
    }
}
