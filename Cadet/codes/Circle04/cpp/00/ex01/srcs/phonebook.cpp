#include "phonebook.hpp"

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
	std::regex regexPhoneNumber("\\b\\d{3}-\\d{4}-\\d{4}\\b");
    std::string darkestSecret;

	std::cout << "FirstName: ";
	std::cin >> firstName;
	std::cout << "LastName: ";
	std::cin >> lastName;
	std::cout << "NickName: ";
	std::cin >> nickName;
	while (true) {
		std::cout << "PhoneNumber(000-0000-0000): ";
		std::cin >> phoneNumber;
		if (std::regex_match(phoneNumber, regexPhoneNumber))
			break;
		std::cout << "잘못된 형태의 연락처입니다." << std::endl;
	}
	std::cout << "DarkestSecert: ";
	std::cin >> darkestSecret;

	this->add(Contact(firstName, lastName, nickName, phoneNumber, darkestSecret));
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
}

void	PhoneBook::add(const Contact& contact) {
	++maxNum;
	contacts[maxNum % maxContacts] = contact;
	if (maxNum - minNum >= maxContacts)
		++minNum;
}

bool	isNums(std::string s) {
	if (s.length() == 0)
		return false;
	for (std::string::size_type i = 0; i < s.length(); i++) {
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
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
			idx = std::stoi(tmp);
		if (idx > -1 && minNum <= idx && maxNum >= idx) {
			contacts[idx % maxContacts].displayContact();
			break;
		}
		std::cin.clear();	// 에러 플래그를 리셋
		std::cout << "해당 번호의 연락처가 없습니다. 다시 입력해주세요." << std::endl;
	}
}
