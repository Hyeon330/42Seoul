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

	Fixed& operator=(const Fixed&);

	int		getRawBits(void) const;
	void	setRawBits(const int);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
