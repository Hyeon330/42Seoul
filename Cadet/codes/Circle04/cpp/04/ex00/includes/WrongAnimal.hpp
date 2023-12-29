#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &ob);
		~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal const &ob);

		void	makeSound() const;
};

#endif