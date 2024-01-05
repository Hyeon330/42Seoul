#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define	ANIMAL_SIZE 6

void	test() {
	system("leaks ex01");
}

int main() {
	// atexit(test);
	Animal *animals[ANIMAL_SIZE];

	for (int i = 0; i < ANIMAL_SIZE; i++) {
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < ANIMAL_SIZE; i++)
		animals[i]->makeSound();

	for (int i = 0; i < ANIMAL_SIZE; i++)
		delete animals[i];

	return 0;
}
