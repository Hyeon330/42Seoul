#include "HumanA.hpp"
using namespace std;

HumanA::HumanA(const string& name, Weapon& weapon) :
	weapon(weapon),
	name(name) {}

HumanA::~HumanA() {}

void	HumanA::attack() const {
	cout << name << " attacks with their " << weapon.getType() << endl;
}
