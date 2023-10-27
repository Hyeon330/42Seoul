#include "HumanB.hpp"
using namespace std;

HumanB::HumanB(string name) :
	name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack() const {
	cout << name << " attacks with their " << weapon->getType() << endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
