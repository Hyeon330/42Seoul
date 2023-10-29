#include "Point.hpp"

int main( void ) {
	Point	a(2, 2);
	Point	b(4, 5);
	Point	c(8, 2);

	if (bsp(a, b, c, Point(3, 3)))
		std::cout << "Good Position." << std::endl;
	else
		std::cout << "Bad Position." << std::endl;

	return 0;
}