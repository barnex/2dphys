#include <X11/Xlib.h>
#include <string>
#include <iostream>

std::string progName = "";

Display* disp;
Window  win;
GC graphics;

int black = 0x000000;
int white = 0xFFFFFF;


void initDisp() {
	disp = XOpenDisplay(NULL);
	if (disp == NULL) {
		std::cerr << progName << ": failed to open display\n";
		exit(1);
	}
}


void initWin() {
	win = XCreateSimpleWindow(disp, DefaultRootWindow(disp),
	                          0, 0, 200, 100, 0, white, white);
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

void flush() {
	XFlush(disp);
}

int main(int argc, char**argv) {
	progName = argv[0];
	initDisp();
	initWin();

	setFg(black);
	drawLine(0, 0, 100, 200);
	flush();

	for ( ;; ) {}

}
