#include "Weapon.hpp"

Weapon::Weapon(std::string type) :
	type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const {
	return type;
}

void    Weapon::setType(const std::string& type) {
	this->type = type;
}
