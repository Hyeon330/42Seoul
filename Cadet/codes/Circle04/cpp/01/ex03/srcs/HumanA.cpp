#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	weapon(weapon),
	name(name) {
	std::cout << "Created HumanA " << name;
	std::cout << " set " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "Deleted HumanA " << name << std::endl;
}

void	HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
