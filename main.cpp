#include "vector.h"
#include <iostream>

int main(){
		vector a = make_vector(1, 0, 0);
		vector b = a;
		b.x = 100;
		b += a;
		b -= a;
		b *= 2;
		std::cout << "a: " << a << "\n";
		std::cout << "b: " << b << "\n";
		std::cout << "a+b: " << a+b << "\n";
		std::cout << "a dot b: " << a.dot(b) << "\n";
		std::cout << "a x b: " << a.cross(b) << "\n";
		std::cout << "a.len(): " << a.len() << "\n";
		std::cout << "b.normalized(): " << b.normalized() << "\n";
		return 0;
}
