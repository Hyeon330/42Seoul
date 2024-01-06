#include "Cat.hpp"

Cat::Cat():
brain(new Brain) {
	type = "Cat";
	std::cout << type << " constructor call" << std::endl;
}

Cat::Cat(const Cat& cat) :
Animal(cat),
brain(new Brain(*cat.brain)) {
	std::cout << type << " copy constructor call" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat " << type << " destructor call" << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*(other.brain));
	}
	std::cout << type << " copy assignment operator call" << std::endl;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "meow~~" << std::endl;
}

Brain*	Cat::getBrain() const {
	return brain;
}
