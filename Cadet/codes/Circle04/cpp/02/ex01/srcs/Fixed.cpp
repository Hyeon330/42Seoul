#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = otherFixed;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	// Round Half Up(기준 반올림) 전략
	this->value = roundf(value * (1 << bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed&	Fixed::operator=(const Fixed& otherFixed) {
	std::cout << "Copy assignment operator called" << std::endl;
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

int	Fixed::toInt() const {
	return value >> bits;
}


float Fixed::toFloat() const {
	return static_cast<float>(value) / (1 << bits);
}
