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
<<<<<<< HEAD:Cadet/codes/Circle04/cpp/00/ex01/srcs/contact.cpp
	std::cout << std::setw(10) << i;
=======
	printName(std::wstring(i));
>>>>>>> 5f35e3f7422df20f11159ef3d8e0ead335995ef1:Cadet/codes/Circle04/cpp/00/ex01/srcs/Contact.cpp
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
