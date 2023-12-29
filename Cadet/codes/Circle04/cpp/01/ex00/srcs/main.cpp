#include "Zombie.hpp"

// void	test() {
// 	system("leaks ex00");
// }

int main() {
    // atexit(test);
    Zombie hello("hello");
    Zombie* world = newZombie("world");

    randomChump("4242");

    hello.announce();
    world->announce();

    delete world;
}
