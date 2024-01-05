#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define	ANIMAL_SIZE 6

void	test() {
	system("leaks ex00");
}

int main() {
	// atexit(test);
	Animal animals[ANIMAL_SIZE];

	for (int i = 0; i < ANIMAL_SIZE; i++) {
		if (i % 2)
			animals[i] = Dog();
		else
			animals[i] = Cat();
	}
	for (int i = 0; i < ANIMAL_SIZE; i++)
		animals[i].makeSound();

	return 0;
}
