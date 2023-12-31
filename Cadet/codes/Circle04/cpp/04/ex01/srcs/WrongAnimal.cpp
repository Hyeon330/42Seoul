#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
	type("WrongAnimal") {
	std::cout << type << " constructor call" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& Wronganimal) {
	*this = Wronganimal;
	std::cout << type << " copy constructor call" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << type << " destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "No type" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
