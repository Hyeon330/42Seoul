#include "ScavTrap.hpp"

int main() {
	ClapTrap	C("C");
	ScavTrap	S("S");

	std::cout << std::endl;

	C.beRepaired(30);
	C.attack("S");
	S.takeDamage(C.getAttackDamage());

	std::cout << std::endl;

	S.attack("C");
	C.takeDamage(S.getAttackDamage());

	std::cout << std::endl;

	C.beRepaired(10);

	std::cout << std::endl;

	S.guardGate();

	std::cout << std::endl;
}
