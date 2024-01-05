#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void	test() {
	system("leaks ex00");
}

int main() {
	// atexit(test);
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl << "====================================" << std::endl << std::endl;

	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound();
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	std::cout << std:: endl << "====================================" << std::endl;

	Animal test = Dog();

	std::cout << test.getType() << " " << std::endl;
	
	test.makeSound();

	return 0;
}