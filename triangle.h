#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
#include <cmath>
#include "vector.h"

class triangle {
public:
    vector a, b, c;

    inline triangle(double ax, double ay, double bx, double by,	double cx,	double cy):
        a(vector(ax, ay)),  b(vector(bx, by)),  c(vector(cx, cy)) {}

    bool inside(vector p);
};

#endif
