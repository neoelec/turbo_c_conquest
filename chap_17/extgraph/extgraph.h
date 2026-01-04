/*
 *      File EXTGRAPH.H
 *      Header for Extended Graphics
 *      1989.2.24. 2.28
 */

#if !defined(__EXTGRAPH_DEF_)
#define __EXTGRAPH_DEF_

#if !defined(_MATH_H)
#include <math.h>
#endif

#if !defined(__GRAPHX_DEF_)
#include <graphics.h>
#endif

typedef enum { false, true } boolean;

void newline(int space);
void cpgotoxy(int x, int y, int space);
void drawborder(int bordercolor);
void changetextstyle(int font, int direction, int charsize);
int gprintf(char *format, ...);
int gprintfxy(int x, int y, char *format, ...);
void rotate3d(double xr, double yr, double zr, double *px, double *py,
              double *pz);
void graph(double y, double z, int *plotted);
void inpolygon(int x, int y, int stangle, int endangle, int xradius,
               int yradius, int delta, int aspect);
void rotinpoly(int x, int y, int stangle, int endangle, int xradius,
               int yradius, int delta, int rotateangle, int aspect);
void randompalette(void);

#endif /* if !defined( __EXTGRAPH_DEF_ ) */
