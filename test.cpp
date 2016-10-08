#include "triangle.h"
#include "vector.h"
#include <assert.h>
#include <iostream>


void test_vector() {
    vector a = vector(1, 0);
    assert(a == a);
    assert(a == vector(1, 0));

    vector b = a;
    assert(b == a);
    assert(a == b);

    b.x = 100;
    assert(b == vector(100, 0));

    b += a;
    assert(b == vector(101, 0));

    b += vector(0, 2);
    assert(b == vector(101, 2));

    b *= 2;
    assert(b == vector(202, 4));

    assert(a == vector(1, 0));
    assert(b.normalized().len() == 1);
    assert(b == vector(202, 4));
    assert(vector(3, 4).len() == 5);

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
}


void test_triangle() {
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(3., 2.)) == true);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(4., 2.)) == true);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(4., 3.)) == true);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(2., 2.)) == true);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(6., 2.)) == false);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(2., 1.)) == false);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(2., 4.)) == false);
    assert(triangle(1., 2., 4., 5., 6., 1.).inside( vector(4., 6.)) == false);
}

int main() {
    test_vector();
    test_triangle();
    std::cout << "OK";
    return 0;
}
