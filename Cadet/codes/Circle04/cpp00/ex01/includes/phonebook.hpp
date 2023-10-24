#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <regex>
# include "contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	void	add();
	void	add(const Contact& contact);
	void	search();
private:
	static const int	maxContacts = 8;
	Contact				contacts[maxContacts];
	int					minNum;
	int					maxNum;
};

#endif