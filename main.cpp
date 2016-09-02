#include "vector.h"
#include <iostream>

int main(){
		vector a = make_vector(1, 0, 0);
		vector b = a;
		b.x = 999;
		std::cout << "a: " << a << "\n";
		std::cout << "b: " << b << "\n";
		std::cout << "a+b: " << a+b << "\n";
		return 0;
}
