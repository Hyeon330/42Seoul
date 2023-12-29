#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap :
public ScavTrap,
public FragTrap {
public:
	DiamondTrap();
	DiamondTrap(const std::string&);
	DiamondTrap(const DiamondTrap&);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap&);

	void	whoAmI();
	using	ScavTrap::attack;
private:
	std::string	name;
};

#endif
