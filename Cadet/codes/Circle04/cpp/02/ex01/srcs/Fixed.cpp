#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor call" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed) {
	std::cout << "Copy constructor call" << std::endl;
	*this = otherFixed;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor call" << std::endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor call" << std::endl;
	this->value = roundf(value * (1 << bits));
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

int	Fixed::toInt() const {
	return value >> bits;
}

float Fixed::toFloat() const {
	return static_cast<float>(value) / (1 << bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
