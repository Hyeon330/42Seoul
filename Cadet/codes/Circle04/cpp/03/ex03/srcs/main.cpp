#include "DiamondTrap.hpp"

int main() {
	DiamondTrap A("A");
	DiamondTrap B("B");

	std::cout << std::endl;

	A.attack("B");
	B.takeDamage(A.getAttackDamage());
	B.beRepaired(20);

	std::cout << std::endl;

	B.attack("A");
	A.takeDamage(B.getAttackDamage());
	A.beRepaired(40);

	std::cout << std::endl;

	A.guardGate();

	std::cout << std::endl;

	B.highFivesGuys();

	std::cout << std::endl;

	A.whoAmI();
	B.whoAmI();

	std::cout << std::endl;

	DiamondTrap C(A);
	DiamondTrap D;
	D = A;
	
	std::cout << std::endl;
}
