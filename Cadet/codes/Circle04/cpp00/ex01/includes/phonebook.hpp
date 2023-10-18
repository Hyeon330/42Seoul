#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <regex>
# include "contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	void	add();
	void	add(const Contact& contact);
	void	search();
	bool	search(int i);
private:
	static const int	maxContacts = 8;
	Contact				contacts[maxContacts];
	int					currIdx;
	int					size;
};

#endif