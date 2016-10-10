#include "x11.h"
#include <unistd.h>

int main(int argc, char**argv) {
	initDisp();
	initWin();

	for ( ;; ) {
		clearWin();
		setFg(black);
		drawLine(0, 0, 100, 200);
		flush();
		usleep(20000);
	}

}
