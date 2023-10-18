#include "contact.hpp"

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
	std::cout << std::setw(10) << std::right << i;
	std::cout << '|';
	std::cout << std::setw(10) << std::right << firstName;
	std::cout << '|';
	std::cout << std::setw(10) << std::right << lastName;
	std::cout << '|';
	std::cout << std::setw(10) << std::right << nickName;
	std::cout << '|' << std::endl;
}

void	Contact::displayContact() {
	std::cout << "FirstName: " << firstName << std::endl;
	std::cout << "LastName: " << lastName << std::endl;
	std::cout << "nickName: " << nickName << std::endl;
	std::cout << "PhoneNumber: " << phoneNumber << std::endl;
	std::cout << "DarkestSecret: " << darkestSecret << std::endl;
}
