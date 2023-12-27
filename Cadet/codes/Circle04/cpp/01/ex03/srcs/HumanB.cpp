#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name(name) {
	std::cout << "Created HumanB " << name << std::endl;
}

HumanB::~HumanB() {
	std::cout << "Deleted HumanB " << name << std::endl;
}

void	HumanB::attack() const {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
	std::cout << name << " set " << weapon.getType() << std::endl;
}
