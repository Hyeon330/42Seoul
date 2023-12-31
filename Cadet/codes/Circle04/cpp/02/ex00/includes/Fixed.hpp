#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	const static int	literalBit = 8;

	int	value;
public:
	Fixed();
	Fixed(const Fixed&);
	~Fixed();
	Fixed& operator=(const Fixed&);

	int		getRawBits(void) const;
	void	setRawBits(const int);
};

#endif
