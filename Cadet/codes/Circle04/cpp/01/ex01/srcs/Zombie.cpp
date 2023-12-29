#include "Zombie.hpp"

Zombie::Zombie() {
	Zombie("Default_Z");
}

Zombie::Zombie(std::string name) :
	name(name) {
	std::cout << "Created " << name << " Zombie" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Deleted " << name << " Zombie" << std::endl;
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiinnzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}
