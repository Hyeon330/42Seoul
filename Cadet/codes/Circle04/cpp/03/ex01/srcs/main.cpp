#include "ClapTrap.hpp"

int main() {
	ClapTrap	hello("hello");
	ClapTrap	world("world");

	hello.attack("world");
	world.takeDamage(2);

	world.beRepaired(1);

	world.attack("hello");
	hello.takeDamage(3);

	hello.beRepaired(1);
}