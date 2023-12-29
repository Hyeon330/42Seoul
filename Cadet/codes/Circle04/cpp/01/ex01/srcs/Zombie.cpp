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

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return  NULL;

	Zombie* ret = new Zombie[N];

	for (int i = 0; i < N; i++)
		ret[i].setName(name);
	return ret;
}
