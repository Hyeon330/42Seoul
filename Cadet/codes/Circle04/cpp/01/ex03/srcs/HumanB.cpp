#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	name(name) {
	std::cout << "Human B " << name << " constructor called" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "Human B destructor called" << std::endl;
}

void	HumanB::attack() const {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
