#include "Zombie.hpp"
#define Z_NUM 5

int main() {
	Zombie*	horde = zombieHorde(Z_NUM, "4242");

	for (int i = 0; i < Z_NUM; ++i) {
		horde[i].announcement();
	}

	delete[] horde;
	return 0;
}
