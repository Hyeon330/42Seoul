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
Fixed	Fixed::operator+(const Fixed& fixed) const {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed& fixed) const {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed& fixed) const {
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed& fixed) const {
	return Fixed(toFloat() / fixed.toFloat());
}

// 증감 연산자
// 참조변수로 리턴하는 이유는 메모리의 오버헤드를 막기위해
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
