#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = otherFixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& otherFixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &otherFixed)
		value = otherFixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const value) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = value;
}
