#include "Zombie.hpp"
#define Z_NUM 7

// void	test() {
// 	system("leaks ex01");
// }

int main() {
	// atexit(test);
	Zombie*	horde = zombieHorde(Z_NUM, "4242");

	for (int i = 0; i < Z_NUM; ++i) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}
