#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << type << " constructor call" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) :
WrongAnimal(wrongCat) {
	std::cout << type << " copy constructor call" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << type << " destructor call" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		type = other.getType();
	std::cout << type << " copy assignment operator call" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "hey~hey~" << std::endl;
}
