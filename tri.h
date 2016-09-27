#ifndef _TRI_H_
#define _TRI_H_

#include <iostream>
#include <cmath>
#include "vector.h"

// triangle
class tri{
	public:
			vector a, b, c;
			bool inside(vector p);
};


bool tri::inside(vector p){
	return false;
}


#endif
