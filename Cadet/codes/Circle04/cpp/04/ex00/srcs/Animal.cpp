#include "Animal.hpp"

Animal::Animal() :
	type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) {
	*this = animal;
}

Animal::~Animal() {
	std::cout << "Animal " << type << " destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}
