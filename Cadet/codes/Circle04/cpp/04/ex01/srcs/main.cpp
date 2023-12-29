#include "ScavTrap.hpp"

int main() {
	ClapTrap	c("C");
	ScavTrap	s("S");

	std::cout << std::endl;

	c.beRepaired(30);
	c.attack("S");
	s.takeDamage(c.getAttackDamage());

	std::cout << std::endl;

	s.attack("C");
	c.takeDamage(s.getAttackDamage());

	std::cout << std::endl;

	c.beRepaired(10);

	std::cout << std::endl;

	s.guardGate();

	std::cout << std::endl;
}
