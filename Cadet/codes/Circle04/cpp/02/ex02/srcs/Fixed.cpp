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

Fixed&	Fixed::operator=(const Fixed& otherFixed) {
	cout << "Copy assignment operator called" << endl;
	if (this != &otherFixed)
		value = otherFixed.getRawBits();
	return *this;
}

ostream& operator<<(ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

// 비교 연산자
bool	Fixed::operator>(const Fixed& fixed) const {
	return value > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed& fixed) const {
	return value < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed& fixed) const {
	return value >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed& fixed) const {
	return value <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed& fixed) const {
	return value == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed& fixed) const {
	return value != fixed.getRawBits();
}

// 산술 연산자
Fixed	Fixed::operator+(const Fixed& fixed) {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed& fixed) {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed& fixed) {
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed& fixed) {
	return Fixed(toFloat() / fixed.toFloat());
}

// 증감 연산자
Fixed&	Fixed::operator++() {
	value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	++value;
	return tmp;
}

Fixed&	Fixed::operator--() {
	value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	--value;
	return tmp;
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	return f1 < f2 ? f1 : f2;
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	return f1 < f2 ? f1 : f2;
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return f1 > f2 ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return f1 > f2 ? f1 : f2;
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
