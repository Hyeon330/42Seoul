#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string&);
	FragTrap(const FragTrap&);
	~FragTrap();

	FragTrap&	operator=(const FragTrap&);

	void	highFivesGuys(void);
};

#endif