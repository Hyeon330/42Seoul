#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) :
	name(name) {}

Zombie::~Zombie() {
	std::cout << "Deleted " << name << std::endl;
}

void	Zombie::announcement() {
	std::cout << name << ": BraiiiiiinnzzZ..." << std::endl;
}
