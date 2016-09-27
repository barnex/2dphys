#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <cmath>

// 2D vector
class vector {
public:
    double x, y;
    double dot(vector x);
    vector cross(vector b);
    double len();
    vector normalized();
};

inline vector make_vector(double x, double y) {
    return vector{x, y};
}

std::ostream& operator<<(std::ostream& out, vector v) {
    out << "(" << v.x << "," << v.y << ")";
    return out;
}

inline vector operator+(vector a, vector b) {
    return make_vector(a.x + b.x, a.y + b.y);
}

inline void operator+=(vector &a, vector b) {
    a.x += b.x;
    a.y += b.y;
}

inline vector operator-(vector a, vector b) {
    return make_vector(a.x - b.x, a.y - b.y);
}

inline vector operator-(vector a) {
    return make_vector(-a.x, -a.y);
}

inline void operator-=(vector &a, vector b) {
    a.x -= b.x;
    a.y -= b.y;
}

inline vector operator*(double s, vector a) {
    return make_vector(s*a.x, s*a.y);
}

inline vector operator*(vector a, double s) {
    return make_vector(s*a.x, s*a.y);
}

inline void operator*=(vector &a, double s) {
    a.x *= s;
    a.y *= s;
}

inline bool operator==(const vector &a, const vector &b) {
    return a.x == b.x && a.y == b.y;
}

// dot product
inline double vector::dot(vector b) {
    return this->x * b.x + this->y * b.y;
}

// length
inline double vector::len() {
    return sqrt(this->dot(*this));
}

// returns a normalized copy
vector vector::normalized() {
    double invlen = (this->len() != 0.0f) ? (1.0f / this->len()) : (0.0f);
    return invlen * *this;
}

#endif
