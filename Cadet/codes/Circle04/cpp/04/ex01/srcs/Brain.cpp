#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor call" << std::endl;
}

Brain::Brain(const Brain& brain) {
	*this = brain;
	std::cout << "Brain copy constructor call" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor call" << std::endl;
}

Brain&  Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			idea[i] = other.idea[i];
	}
	std::cout << "Brain assignment operator call" << std::endl;
	return *this;
}
