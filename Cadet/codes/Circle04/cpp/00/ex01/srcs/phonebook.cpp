#include "Phonebook.hpp"

static bool	isNums(std::string s) {
	if (s.length() == 0)
		return false;
	for (std::string::size_type i = 0; i < s.length(); i++) {
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

static bool	setInfo(std::string title, std::string *info) {
	while (info->length() <= 0) {
		std::cout << title;
		std::getline(std::cin, *info);
		if (std::cin.eof())
			return false;
	}
	return true;
}

PhoneBook::PhoneBook() : 
	minNum(0),
	maxNum(-1) {
	for (int i = 0; i < maxContacts; ++i)
		contacts[i] = Contact();
}

void	PhoneBook::add() {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
    std::string darkestSecret;

	if (!setInfo("FirstName: ", &firstName))
		return ;
	if (!setInfo("LastName: ", &lastName))
		return ;
	if (!setInfo("NickName: ", &nickName))
		return ;
	while (true) {
		phoneNumber = "";
		if (!setInfo("PhoneNumber: ", &phoneNumber))
			return ;
		if (isNums(phoneNumber))
			break ;
		std::cout << "숫자를 입력하세요." << std::endl;
	}
	if (!setInfo("DarkestSecert: ", &darkestSecret))
		return ;

	this->add(Contact(firstName, lastName, nickName, phoneNumber, darkestSecret));
}

void	PhoneBook::add(const Contact& contact) {
	++maxNum;
	contacts[maxNum % maxContacts] = contact;
	if (maxNum - minNum >= maxContacts)
		++minNum;
}

void	PhoneBook::search() {
	std::string tmp;
	int			idx;

	if (maxNum < 0) {
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
	for (int i = minNum; i <= maxNum; ++i)
		contacts[i % maxContacts].displayNames(i);

	while (true) {
		std::cout << "검색할 번호: ";
		std::getline(std::cin, tmp);
		if (std::cin.eof())
			break;
		idx = -1;
		if (isNums(tmp))
			idx = std::atoi(tmp.c_str());
		if (idx > -1 && minNum <= idx && maxNum >= idx) {
			contacts[idx % maxContacts].displayContact();
			break;
		}
		std::cout << "해당 번호의 연락처가 없습니다. 다시 입력해주세요." << std::endl;
	}
}
