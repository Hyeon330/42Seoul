#include "Dog.hpp"

Dog::Dog():
brain(new Brain) {
	type = "Dog";
	std::cout << type << " constructor call" << std::endl;
}

Dog::Dog(const Dog& dog) :
Animal(dog),
brain(new Brain(*(dog.brain))) {
	std::cout << type << " copy constructor call" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog " << type << " destructor call" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*(other.brain));
	}
	std::cout << type << " copy assignment operator call" << std::endl;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "BOW!! WOW!!" << std::endl;
}

Brain*	Dog::getBrain() const {
	return brain;
}
