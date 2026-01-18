/*
 *      File TURTLE.C
 *      Turtle Graphics Library
 *      1989.2.20. 2.25
 */

#include <graphics.h>
#include <math.h>

#include "turtle.h"

static boolean _pendown = true;
static boolean _scrunch = true;

static int _window_x = 0, _window_y = 0, _window_wid, _window_hgt;
static int _origin_x = 0, _origin_y = 0;
static double _xcor = 0., _ycor = 0.;
static double _heading = NORTH;
static double _ratio = 1.;

#define movetoxy(xcor, ycor)                                                \
    do {                                                                    \
        moveto(_origin_x + (int)round(xcor), _origin_y - (int)round(ycor)); \
    } while (0)

void back(double dist)
{
    forward(-dist);
}

void centerturtle(int thickness)
{
    setlinestyle(CENTER_LINE, 0,
                 (thickness == THIN) ? NORM_WIDTH : THICK_WIDTH);
}

void clearscreen(void)
{
    clearviewport();
    home();
}

void dashedturtle(int thickness)
{
    setlinestyle(DASHED_LINE, 0,
                 (thickness == THIN) ? NORM_WIDTH : THICK_WIDTH);
}

void dottedturtle(int thickness)
{
    setlinestyle(DOTTED_LINE, 0,
                 (thickness == THIN) ? NORM_WIDTH : THICK_WIDTH);
}

void drawturtlewindow(void)
{
    rectangle(0, 0, _window_wid - 1, _window_hgt - 1);
}

void forward(double dist)
{
    double dx, dy;

    dx = dist * _sin(_heading);
    dy = dist * _cos(_heading);

    if (_scrunch) {
        dy *= _ratio;
    }

    _xcor += dx;
    _ycor += dy;

    if (!_pendown) {
        movetoxy(_xcor, _ycor);
    } else {
        lineto(_origin_x + (int)round(_xcor), _origin_y - (int)round(_ycor));
    }
}

double heading(void)
{
    return fmod(_heading, 360.);
}

void home(void)
{
    _xcor = 0.;
    _ycor = 0.;
    _heading = NORTH;
    _pendown = true;
    setposition(0., 0.);
}

int homex(void)
{
    return _origin_x;
}

int homey(void)
{
    return _origin_y;
}

void initturtle(void)
{
    int xasp, yasp;

    _window_x = 0;
    _window_y = 0;
    _window_wid = getmaxx() + 1;
    _window_hgt = getmaxy() + 1;
    getaspectratio(&xasp, &yasp);
    _scrunch = true;
    _ratio = (double)xasp / (double)yasp;
    turtlewindow(0, 0, _window_wid, _window_hgt);
}

void nowrap(void)
{
    setviewport(_window_x, _window_y, _window_wid, _window_hgt, true);
}

void pendown(void)
{
    _pendown = true;
}

void penup(void)
{
    _pendown = false;
}

double scrunch(void)
{
    return _ratio;
}

void setheading(double angle)
{
    _heading = fmod(angle, 360.);
}

void setposition(double x, double y)
{
    _xcor = x;
    _ycor = y;

    if (_scrunch) {
        _ycor *= _ratio;
    }

    movetoxy(_xcor, _ycor);
}

void setscrunch(boolean scrunch)
{
    _scrunch = (scrunch == false) ? false : true;
}

void setx(double x)
{
    _xcor = x;
    movetoxy(_xcor, _ycor);
}

void sety(double y)
{
    _ycor = y;

    if (_scrunch) {
        _ycor *= _ratio;
    }

    movetoxy(_xcor, _ycor);
}

void solidturtle(int thickness)
{
    setlinestyle(SOLID_LINE, 0, (thickness == THIN) ? NORM_WIDTH : THICK_WIDTH);
}

void turnleft(double angle)
{
    _heading = fmod(_heading - angle, 360.);
}

void turnright(double angle)
{
    _heading = fmod(_heading + angle, 360.);
}

boolean turtlestate(void)
{
    return _pendown;
}

void turtlewindow(int x, int y, int width, int height)
{
    setviewport(x, y, x + width - 1, y + height - 1, true);
    _origin_x = width / 2;
    _origin_y = height / 2;
    home();
}

void wrap(void)
{
    setviewport(_window_x, _window_y, _window_wid, _window_hgt, false);
}

double xcor(void)
{
    return _xcor;
}

double ycor(void)
{
    return _ycor;
}

double round(double x)
{
    return ((x > 0.) ? floor(x + .5) : ceil(x - .5));
}
