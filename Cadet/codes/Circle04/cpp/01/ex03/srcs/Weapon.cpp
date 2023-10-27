#include "Weapon.hpp"
using namespace std;

Weapon::Weapon() {}

Weapon::Weapon(const string& type) :
	type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const {
	return type;
}

void    Weapon::setType(const std::string& type) {
	this->type = type;
}
