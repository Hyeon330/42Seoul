#include "Zombie.hpp"

int main() {
    Zombie hello("hello");
    Zombie* world = newZombie("world");

    randomChump("4242");

    hello.announcement();
    world->announcement();

    delete world;
}
