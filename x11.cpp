#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <unistd.h>

static Display* disp;
static Window  win;
static GC graphics;

int W = 800;
int H = 600;

int black = 0x000000;
int white = 0xFFFFFF;


void initDisp() {
	disp = XOpenDisplay(NULL);
	if (disp == NULL) {
		std::cerr << "failed to open display\n";
		exit(1);
	}
}


void initWin() {
	win = XCreateSimpleWindow(disp, DefaultRootWindow(disp),
	                          0, 0, W, H, 0, white, white);
	XSelectInput(disp, win, StructureNotifyMask);
	XMapWindow(disp, win);
	graphics = XCreateGC(disp, win, 0, NULL);
	// Wait for window to appear
	XEvent ev;
	while(ev.type != MapNotify) {
		XNextEvent(disp, &ev);
	}
}


void drawLine(double x1, double y1, double x2, double y2) {
	XDrawLine(disp, win, graphics, x1, y1, x2, y2);
}

void setFg(int color) {
	XSetForeground(disp, graphics, color);
}

void clearWin() {
	XClearWindow(disp, win);
}

void flush() {
	XFlush(disp);
}


