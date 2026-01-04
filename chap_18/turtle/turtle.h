/*
 *      File TURTLE.H
 *      Header for Turtle Graphics
 *      1989.2.20. 2.25
 */

#if !defined(__TURTLE_DEF_)
#define __TURTLE_DEF_

#if !defined(_MATH_H)
#include <math.h>
#endif

#if !defined(__GRAPHX_DEF_)
#include <graphics.h>
#endif

typedef enum { false, true } boolean;

#define NORTH 0.
#define EAST 90.
#define SOUTH 180.
#define WEST 270.
#define THIN 0
#define THICK 1

void back(double dist);
void centerturtle(int thickness);
void clearscreen(void);
void dashedturtle(int thickness);
void dottedturtle(int thickness);
void drawturtlewindow(void);
void forward(double dist);
double heading(void);
void home(void);
int homex(void);
int homey(void);
void initturtle(void);
void nowrap(void);
void pendown(void);
void penup(void);
double round(double x);
double scrunch(void);
void setheading(double angle);
void setposition(double x, double y);
void setscrunch(boolean scrunch);
void setx(double x);
void sety(double y);
void solidturtle(int thickness);
void turnleft(double angle);
void turnright(double angle);
boolean turtlestate(void);
void turtlewindow(int x, int y, int width, int height);
void wrap(void);
double xcor(void);
double ycor(void);

#define clean() clearviewport()
#define deg(rad) ((double)(rad) * 180. / M_PI)
#define dot(x, y) putpixel(screenx(x), screeny(y), pencolor())
#define pencolor() getcolor()
#define rad(degree) ((double)(degree) * M_PI / 180.)
#define screenx(x) ((int)round((double)(x)) + homex())
#define screeny(y) (homey() - (int)round((double)(y)))
#define setpencolor(color) setcolor(color)
#define turtlex(x) ((double)((int)(x) - homex()))
#define turtley(y) ((double)(homey() - (int)(y)))
#define _cos(degree) cos(rad(degree))
#define _sin(degree) sin(rad(degree))
#define _tan(degree) tan(rad(degree))

#endif /* if !defined( __TURTLE_DEF_ ) */
