#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) :
	weapon(weapon),
	name(name) {}

HumanA::~HumanA() {}

void	HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
