#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie* zombie = new Zombie(name);
	zombie->announcement();
	delete zombie;
}