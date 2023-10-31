#include "Fixed.hpp"
using namespace std;

Fixed::Fixed() : value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& otherFixed) {
	cout << "Copy constructor called" << endl;
	*this = otherFixed;
}

Fixed::Fixed(const int value) {
	cout << "Int constructor called" << endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value) {
	cout << "Float constructor called" << endl;
	// Round Half Up(기준 반올림) 전략
	this->value = roundf(value * (1 << bits));
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

ostream& operator<<(ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed&	Fixed::operator=(const Fixed& otherFixed) {
	cout << "Copy assignment operator called" << endl;
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
