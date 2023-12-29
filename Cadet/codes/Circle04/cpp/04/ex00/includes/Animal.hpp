#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal&);
	~Animal();

	Animal&	operator=(const Animal&);

	virtual void	makeSound();
};

# endif