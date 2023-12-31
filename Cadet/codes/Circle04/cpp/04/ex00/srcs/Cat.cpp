#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << type << " constructor call" << std::endl;
}

Cat::Cat(const Cat& cat) {
	*this = cat;
	std::cout << type << " copy constructor call" << std::endl;
}

Cat::~Cat() {
	std::cout << type << " destructor call" << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other)
		type = other.getType();
	std::cout << type << " copy assignment operator call" << std::endl;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "hey~hey~" << std::endl;
}
