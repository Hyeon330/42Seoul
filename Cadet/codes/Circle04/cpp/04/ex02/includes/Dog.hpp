#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
private:
	Brain*	brain;
public:
	Dog();
	Dog(const Dog&);
	~Dog();

	Dog&	operator=(const Dog&);

	void	makeSound() const;
	Brain*	getBrain() const;
};

#endif