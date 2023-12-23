#include "Contact.hpp"

Contact::Contact() : 
	firstName(""),
	lastName(""),
	nickName(""),
	phoneNumber("") {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) : 
	firstName(firstName),
	lastName(lastName),
	nickName(nickName),
	phoneNumber(phoneNumber),
	darkestSecret(darkestSecret) {}

void	Contact::displayNames(int i) {
	std::cout << '|';
	printName(std::to_string(i));
	std::cout << '|';
	printName(firstName);
	std::cout << '|';
	printName(lastName);
	std::cout << '|';
	printName(nickName);
	std::cout << '|' << std::endl;
}

void	Contact::printName(std::string text) {
	std::cout << std::right;
	if (text.length() <= 10)
		std::cout << std::setw(10) << text;
	else {
		std::cout << std::setw(9) << text.substr(0, 9);
		std::cout << '.';
	}
}

void	Contact::displayContact() {
	std::cout << "FirstName: " << firstName << std::endl;
	std::cout << "LastName: " << lastName << std::endl;
	std::cout << "nickName: " << nickName << std::endl;
	std::cout << "PhoneNumber: " << phoneNumber << std::endl;
	std::cout << "DarkestSecret: " << darkestSecret << std::endl;
}
