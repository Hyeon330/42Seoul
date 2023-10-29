#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& p) : x(p.getX()), y(p.getY()) {}

Point::~Point() {}

Point&  Point::operator=(const Point& p) {
	if (this != &p) {
		getX().setRawBits(p.getX().getRawBits());
		getY().setRawBits(p.getY().getRawBits());
	}
	return *this;
}

Fixed	Point::getX() const {
	return x;
}

Fixed	Point::getY() const {
	return y;
}
