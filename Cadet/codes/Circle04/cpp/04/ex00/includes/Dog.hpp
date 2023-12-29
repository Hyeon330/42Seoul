#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog&);
	~Dog();

	Dog&	operator=(const Dog&);

	void	makeSound();
};

#endif