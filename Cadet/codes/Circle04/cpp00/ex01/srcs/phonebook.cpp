#include "phonebook.hpp"

PhoneBook::PhoneBook() : currIdx(-1), size(0) {
	for (int i = 0; i < maxContacts; ++i)
		contacts[i] = Contact();
}

void	PhoneBook::add() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
    std::string darkestSecret;
	std::regex regexPhoneNumber("\\b\\d{3}-\\d{4}-\\d{4}\\b");

	std::cout << "FirstName: ";
	std::cin >> firstName;
	std::cout << "LastName: ";
	std::cin >> lastName;
	std::cout << "NickName: ";
	std::cin >> nickName;
	while (true)
	{
		std::cout << "PhoneNumber(000-0000-0000): ";
		std::cin >> phoneNumber;
		if (std::regex_match(phoneNumber, regexPhoneNumber))
			break;
		std::cout << "잘못된 형태의 연락처입니다." << std::endl;
	}
	std::cout << "DarkestSecert: ";
	std::cin >> darkestSecret;

	this->add(Contact(firstName, lastName, nickName, phoneNumber, darkestSecret));
}

void	PhoneBook::add(const Contact& contact) {
	contacts[currIdx = ++currIdx % maxContacts] = contact;
	if (size < maxContacts)
		size++;
}

void	PhoneBook::search() {
	int	idx;

	if (!size) {
		std::cout << "아직 저장된 연락처가 없습니다." << std::endl;
		return ;
	}
	std::cout << '|';
	std::cout << std::setw(10) << std::right << "Index";
	std::cout << '|';
	std::cout << std::setw(10) << std::right << "FirstName";
	std::cout << '|';
	std::cout << std::setw(10) << std::right << "LastName";
	std::cout << '|';
	std::cout << std::setw(10) << std::right << "NickName";
	std::cout << '|' << std::endl;
	for (int i = 0; i < size; ++i)
		contacts[i].displayNames(i);

	while (true) {
		std::cout << "검색할 번호: ";
		std::cin >> idx;
		if (this->search(idx))
			break;
		std::cin >> idx;
	}
}

bool	PhoneBook::search(int i) {
	if (size <= i) {
		std::cout << "해당 번호의 연락처가 없습니다." << std::endl;
		return 0;
	}
	contacts[i].displayContact();
	return 1;
}
