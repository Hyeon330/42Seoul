#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
protected:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap&);
	ClapTrap(const std::string&);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap&);

	void	attack(const std::string&);
	void	takeDamage(unsigned int);
	void	beRepaired(unsigned int);
	
	int		getAttackDamage();
};

#endif
