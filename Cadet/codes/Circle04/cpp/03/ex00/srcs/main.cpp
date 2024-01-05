#include "ClapTrap.hpp"

int main() {
	ClapTrap	C1("C1");
	ClapTrap	C2("C2");

	C1.attack("C2");
	C2.takeDamage(2);

	C2.beRepaired(1);

	C2.attack("C1");
	C1.takeDamage(3);

	C1.beRepaired(1);
}