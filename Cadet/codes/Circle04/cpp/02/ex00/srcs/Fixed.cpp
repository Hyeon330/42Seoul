#include "Fixed.hpp"
using namespace std;

Fixed::Fixed() : value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed& otherFixed) {
	cout << "Copy constructor called" << endl;
	*this = otherFixed;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

Fixed&	Fixed::operator=(const Fixed& otherFixed) {
	cout << "Copy assignment operator called" << endl;
	if (this != &otherFixed)
		value = otherFixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	cout << "getRawBits member function called" << endl;
	return value;
}

void	Fixed::setRawBits(int const value) {
	cout << "setRawBits member function called" << endl;
	this->value = value;
}
