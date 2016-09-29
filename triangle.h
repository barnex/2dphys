#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
#include <cmath>
#include "vector.h"

class triangle {
public:
	vector a, b, c;

	triangle(double ax,	double ay,	double bx,	double by,	double cx,	double cy);

	bool inside(vector p);
};


triangle::triangle(double ax,	double ay,	double bx,	double by,	double cx,	double cy):
	a(vector(ax, ay)),  b(vector(bx, by)),  c(vector(cx, cy)) {}

bool triangle::inside(vector pt) {
	double x1 = this->a.x;
	double y1 = this->a.y;
	double x2 = this->b.x;
	double y2 = this->b.y;
	double x3 = this->c.x;
	double y3 = this->c.y;

	double det = (y2-y3)*(x1-x3) +  (x3-x2)*(y1-y3);
	double l1 =  ((y2-y3)*(pt.x-x3) + (x3-x2)*(pt.y-y3)) / det;
	double l2 =  ((y3-y1)*(pt.x-x3) + (x1-x3)*(pt.y-y3)) / det;
	double l3 = 1. - l1 - l2;

	return l1 >= 0. && l1 <= 1. &&
	       l2 >= 0. && l2 <= 1. &&
	       l3 >= 0. && l3 <= 1.;
}


#endif
