#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <cmath>

class vector{
	public:
			double x, y, z;
			double dot(vector x);
			vector cross(vector b);
			double len();
			vector normalized();
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

// cross product
vector vector::cross(vector b) { 
	return make_vector( this->y*b.z - this->z*b.y,  this->z*b.x - this->x*b.z, this->x*b.y - this->y*b.x); 
}

// lenght of the 3-components vector
double vector::len() {
	return sqrt(this->dot(*this));
}

// returns a normalized copy of the 3-components vector
vector vector::normalized(){
    double invlen = (this->len() != 0.0f) ? (1.0f / this->len()) : (0.0f);
	return invlen * *this;
}


#endif
