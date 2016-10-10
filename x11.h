#ifndef _X11_H_
#define _X11_H_

#include <X11/Xlib.h>

extern int W;
extern int H;
extern int black;
extern int white;


void initDisp();

void initWin();

void drawLine(double x1, double y1, double x2, double y2);

void setFg(int color);

void clearWin();

void flush();


#endif
