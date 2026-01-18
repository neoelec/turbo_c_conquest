/*
 *      File EXTGRAPH.C
 *      Extended Graphics Library
 *      1989.2.24. 2.28
 */

#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "extgraph.h"

void newline(int space)
{
    moveto(0, gety() + textheight("H") + space);
}

void cpgotoxy(int x, int y, int space)
{
    moveto(textwidth("W") * x, (textheight("H") + space) * y);
}

/*
 *      drawborder: Draw a rectangular around the current viewport.
 */
void drawborder(int bordercolor)
{
    int color;
    struct viewporttype vp;

    color = getcolor();
    setcolor(bordercolor); /* set current drawing color to bordercolor */
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    getviewsettings(&vp);
    rectangle(0, 0, vp.right - vp.left, vp.bottom - vp.top);
    setcolor(color);
}

/*
 *      changetextstyle: Similar to settextstyle, but checks for errors
 *                       that might occur while loading the font file.
 */

void changetextstyle(int font, int direction, int charsize)
{
    int errorcode;

    graphresult(); /* clear error code */
    settextstyle(font, direction, charsize);
    errorcode = graphresult(); /* check result */

    if (errorcode != grOk) { /* if error occured */
        closegraph();
        cputs(" Graphics System Error: ");
        cputs(grapherrormsg(errorcode));
        cputs("\r\n");
        exit(EXIT_FAILURE);
    }
}

/*
 *      gprintf: Used like printf except the output is sent to the
 *               screen in graphics mode at CP.
 */
int gprintf(char *format, ...)
{
    char str[256];   /* buffer to build string into  */
    int cnt;         /* result of sprintf for return */
    va_list arglist; /* argument list pointer        */

    va_start(arglist, format);            /* initialize va... functions   */
    cnt = vsprintf(str, format, arglist); /* prints string to buffer      */
    outtext(str);                         /* send string in graphics mode */
    va_end(arglist);                      /* close va... functions        */

    return cnt; /* return the conversion count */
}

/*
 *      gprintfxy: Used like printf except the output is sent to the
 *                 screen in graphics mode at the specified coordinates.
 */
int gprintfxy(int x, int y, char *format, ...)
{
    char str[256];   /* buffer to build string into  */
    int cnt;         /* result of sprintf for return */
    va_list arglist; /* argument list pointer        */

    va_start(arglist, format);            /* initialize va... functions   */
    cnt = vsprintf(str, format, arglist); /* prints string to buffer      */
    outtextxy(x, y, str);                 /* send string in graphics mode */
    va_end(arglist);                      /* close va... functions        */

    return cnt; /* return the conversion count */
}

/* Rotation order :  z axis -> y axis -> x axis */
void rotate3d(double xr, double yr, double zr, double *px, double *py,
              double *pz)
{
    double x = *px, y = *py, z = *pz;
    double x1, y1, z1, x2, y2, z2, x3, y3, z3;

    x1 = x * cos(zr) - y * sin(zr);
    y1 = x * sin(zr) + y * cos(zr);
    z1 = z;

    x2 = x1 * cos(yr) - z1 * sin(yr);
    y2 = y1;
    z2 = x1 * sin(yr) + z1 * cos(yr);

    x3 = x2;
    y3 = y2 * cos(xr) - z2 * sin(xr);
    z3 = y2 * sin(xr) + z2 * cos(xr);

    *px = x3;
    *py = y3;
    *pz = z3;
}

void graph(double y, double z, int *plotted)
{
    int xx, yy, xasp, yasp;

    getaspectratio(&xasp, &yasp);
    xx = getmaxx() / 2 + (int)y;
    yy = getmaxy() / 2 - (int)(z * xasp / yasp);

    if (*plotted == false) {
        moveto(xx, yy);
    } else {
        lineto(xx, yy);
    }

    *plotted = true;
}

/* Draw an inscribed polygon                                                 */
/* If circle, inpolygon function is approx. 4 times slower                   */
/*            than circle function because of lineto function.               */
/* If circle && radius > 100, delta = 4, 5, 6 or 8                           */
/* If circle && radius < 100, delta = 10, 12 or 15                           */
void inpolygon(int x, int y, int stangle, int endangle, int xradius,
               int yradius, int delta, int aspect)
{
    int xasp, yasp, angle, cpx, cpy;
    double _angle, _delta, rx, ry, ratio, rd = M_PI / 180.;

    if (stangle >= endangle) {
        return;
    }

    if ((xradius < 1) || (yradius < 1)) {
        return;
    }

    if (delta < 1) {
        return;
    }

    getaspectratio(&xasp, &yasp);
    ratio = (aspect != 0) ? (double)xasp / (double)yasp : 1.;
    cpx = getx();
    cpy = gety();

    angle = stangle;
    _angle = (double)angle * rd;
    _delta = (double)delta * rd;
    rx = (double)xradius;
    ry = (double)yradius;

    moveto(x + (int)(rx * cos(_angle)), y - (int)(ry * sin(_angle) * ratio));

    for (; angle <= endangle; angle += delta, _angle += _delta) {
        lineto(x + (int)(rx * cos(_angle)),
               y - (int)(ry * sin(_angle) * ratio));
    }

    moveto(cpx, cpy);
}

/* Draw a rotated inpolygon */
void rotinpoly(int x, int y, int stangle, int endangle, int xradius,
               int yradius, int delta, int rotateangle, int aspect)
{
    int xasp, yasp, angle, cpx, cpy;
    double _angle, _delta, rx, ry, cosine, sine, px, py;
    double ratio, rd = M_PI / 180.;

    if (stangle >= endangle) {
        return;
    }

    if ((xradius < 1) || (yradius < 1)) {
        return;
    }

    if (delta < 1) {
        return;
    }

    getaspectratio(&xasp, &yasp);
    ratio = (aspect != 0) ? (double)xasp / (double)yasp : 1.;
    cpx = getx();
    cpy = gety();

    angle = stangle;
    _angle = (double)angle * rd;
    _delta = (double)delta * rd;
    rx = (double)xradius;
    ry = (double)yradius;
    cosine = cos((double)rotateangle * rd);
    sine = sin((double)rotateangle * rd);

    px = rx * cos(_angle);
    py = ry * sin(_angle);
    moveto(x + (int)(px * cosine - py * sine),
           y - (int)((px * sine - py * cosine) * ratio));

    for (; angle <= endangle; angle += delta, _angle += _delta) {
        px = rx * cos(_angle);
        py = ry * sin(_angle);
        lineto(x + (int)(px * cosine - py * sine),
               y - (int)((px * sine + py * cosine) * ratio));
    }

    moveto(cpx, cpy);
}

void randompalette(void)
{
    while (!kbhit()) {
        setpalette(random(MAXCOLORS - 1) + 1, random(65));
    }
}
