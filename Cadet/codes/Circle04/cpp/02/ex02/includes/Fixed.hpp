#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	const static int	bits = 8;

	int	value;
public:
	Fixed();
	Fixed(const Fixed&);
	Fixed(const int);
	Fixed(const float);
	~Fixed();

	Fixed&	operator=(const Fixed&);
	friend std::ostream& operator<<(std::ostream&, const Fixed&);

	// 비교 연산자
	bool	operator>(const Fixed&) const;
	bool	operator<(const Fixed&) const;
	bool	operator>=(const Fixed&) const;
	bool	operator<=(const Fixed&) const;
	bool	operator==(const Fixed&) const;
	bool	operator!=(const Fixed&) const;

	// 산술 연산자
	Fixed	operator+(const Fixed&);
	Fixed	operator-(const Fixed&);
	Fixed	operator*(const Fixed&);
	Fixed	operator/(const Fixed&);
	
	// 증감 연산자
	Fixed&	operator++();		// 전위
	Fixed	operator++(int);	// 후위
	Fixed&	operator--();		// 전위
	Fixed	operator--(int);	// 후위

	static Fixed&	min(Fixed& f1, Fixed& f2);
	const static Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&	max(Fixed& f1, Fixed& f2);
	const static Fixed&	max(const Fixed& f1, const Fixed& f2);

	int		getRawBits(void) const;
	void	setRawBits(const int);

	float	toFloat(void) const;
	int		toInt(void) const;
};

#endif
