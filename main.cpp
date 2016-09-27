#include "vector.h"
#include <iostream>
#include <assert.h>

int main(){
		vector a = make_vector(1, 0);
		assert(a == a);
		assert(a == make_vector(1, 0));

		vector b = a;
		assert(b == a);
		assert(a == b);

		b.x = 100;
		assert(b == make_vector(100, 0));

		b += a;
		assert(b == make_vector(101, 0));

		b += make_vector(0, 2);
		assert(b == make_vector(101, 2));

		b *= 2;
		assert(b == make_vector(202, 4));

		assert(a == make_vector(1, 0));
		assert(b.normalized().len() == 1);
		assert(b == make_vector(202, 4));
		assert(make_vector(3, 4).len() == 5);



		std::cout << "a: " << a << "\n";
		std::cout << "b: " << b << "\n";
		return 0;
}
