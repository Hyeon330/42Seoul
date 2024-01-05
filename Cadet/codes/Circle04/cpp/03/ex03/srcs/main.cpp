#include "DiamondTrap.hpp"

int main() {
	DiamondTrap a("A");
	DiamondTrap b("B");

	std::cout << "-----------------------------------------------------------" << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(3);
	std::cout << "-----------------------------------------------------------" << std::endl;
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	a.beRepaired(55);
	std::cout << "-----------------------------------------------------------" << std::endl;
	a.guardGate();
	std::cout << "-----------------------------------------------------------" << std::endl;
	b.highFivesGuys();
	std::cout << "-----------------------------------------------------------" << std::endl;
	a.whoAmI();
	b.whoAmI();
	std::cout << "-----------------------------------------------------------" << std::endl;
	DiamondTrap c(a);
	DiamondTrap d;
	d = a;
	std::cout << "-----------------------------------------------------------" << std::endl;
}