#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class vector{
	public:
			double x, y, z;
			double dot(vector x);
};

vector make_vector(double x, double y, double z){
	return vector{x, y, z};
}

std::ostream& operator<<(std::ostream& out, vector v){
	out << "(" << v.x << "," << v.y << "," << v.z << ")";
	return out;
}

vector operator+(vector a, vector b) {
    return make_vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

void operator+=(vector &a, vector b) {
    a.x += b.x; 
	a.y += b.y; 
	a.z += b.z;
}

vector operator-(vector a, vector b) {
    return make_vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

vector operator-(vector a) {
    return make_vector(-a.x, -a.y, -a.z);
}

void operator-=(vector &a, vector b) {
    a.x -= b.x; 
	a.y -= b.y; 
	a.z -= b.z;
}

vector operator*(double s, vector a) {
    return make_vector(s*a.x, s*a.y, s*a.z);
}

vector operator*(vector a, double s) {
    return make_vector(s*a.x, s*a.y, s*a.z);
}

void operator*=(vector &a, double s) {
    a.x *= s; 
	a.y *= s; 
	a.z *= s;
}



// dot product
double vector::dot(vector b) { 
	return this->x * b.x + this->y * b.y + this->z * b.z;
}

/*
// cross product
vector cross(vector a, vector b) { 
	return make_vector( a.y*b.z - a.z*b.y,  a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); 
}

// lenght of the 3-components vector
double len(vector a) {
	return sqrtf(dot(a,a));
}

// returns a normalized copy of the 3-components vector
vector normalized(vector a){
    double veclen = (len(a) != 0.0f) ? 1.0f / len(a) : 0.0f;
	return veclen * a;
}

// square
double pow2(double x){
	return x * x;
}


// pow(x, 3)
double pow3(double x){
	return x * x * x;
}


// pow(x, 4)
double pow4(double x){
	double s = x*x;
	return s*s;
}
*/

#endif
