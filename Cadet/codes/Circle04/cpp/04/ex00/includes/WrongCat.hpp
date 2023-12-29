#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        WrongCat(WrongCat const &ob);
        ~WrongCat();

        WrongCat& operator=(WrongCat const &ob);

        void	makeSound() const;
};

#endif