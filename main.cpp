#include "vector.h"
#include <iostream>

int main(){
		vector a = make_vector(0, 0, 0);
		vector b = a;
		b.x = 999;
		std::cout << b << "\n";
		std::cout << a << "\n";
		return 0;
}
