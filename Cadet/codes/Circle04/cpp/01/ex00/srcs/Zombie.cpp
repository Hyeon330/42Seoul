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

void	Zombie::announcement() {
	std::cout << name << ": BraiiiiiinnzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name) {
	Zombie z(name);
    z.announcement();
}
