#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return nullptr;

	Zombie* ret = new Zombie[N];

	for (int i = 0; i < N; i++)
		ret[i].setName(name);
	return ret;
}
