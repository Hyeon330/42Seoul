#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << type << " constructor call" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
	std::cout << type << " copy constructor call" << std::endl;
}

Dog::~Dog() {
	std::cout << type << " destructor call" << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other)
		type = other.getType();
	std::cout << type << " copy assignment operator call" << std::endl;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "BOW!! WOW!!" << std::endl;
}
