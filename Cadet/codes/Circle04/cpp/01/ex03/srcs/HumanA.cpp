#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) :
	weapon(weapon),
	name(name) {
	std::cout << "HumanA " << name << " constuctor called" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "Human A destructor called" << std::endl;
}

void	HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
