#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	const static int	literalBit = 8;

	int	value;
public:
	Fixed();
	Fixed(const Fixed& otherFixed);
	~Fixed();
	Fixed& operator=(const Fixed& otherFixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
