#include "Point.hpp"

Fixed   shoelace(const Point& a, const Point& b, const Point& c) {
	Fixed ret;

	ret = a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY();
	ret = ret - (b.getX() * a.getY() + c.getX() * b.getY() + a.getX() * c.getY());

	if (ret.toFloat() < 0)
		ret = ret * -1;
	return ret / 2;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	return (shoelace(a, b, point) + shoelace(b, c, point) + shoelace(a, c, point)) <= shoelace(a, b, c);
}
