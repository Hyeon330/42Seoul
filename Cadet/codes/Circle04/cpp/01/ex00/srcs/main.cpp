#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("hello");
    Zombie* zombie2 = newZombie("world");

    zombie1->announcement();
    zombie2->announcement();

    randomChump("4242");

    delete zombie1;
    delete zombie2;
}
