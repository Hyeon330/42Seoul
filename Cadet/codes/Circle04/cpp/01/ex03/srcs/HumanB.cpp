#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack() const {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
