#include "Animal.hpp"

Animal::Animal() :
	type("Animal") {
	std::cout << type << " constructor call" << std::endl;
}

Animal::Animal(const Animal& animal) {
	*this = animal;
	std::cout << type << " copy constructor call" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal " << type << " destructor call" << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other)
		type = other.type;
	std::cout << type << " copy assignment operator call" << std::endl;
	return *this;
}

void	Animal::makeSound() const {
	std::cout << "No type" << std::endl;
}

std::string	Animal::getType() const {
	return type;
}
