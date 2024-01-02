#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor call" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed) {
	std::cout << "Copy constructor call" << std::endl;
	*this = otherFixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor call" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& otherFixed) {
	std::cout << "Copy assignment operator call" << std::endl;
	if (this != &otherFixed)
		value = otherFixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	return value;
}

void	Fixed::setRawBits(int const value) {
	this->value = value;
}
