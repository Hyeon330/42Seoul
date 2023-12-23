#include "Phonebook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true) {
		std::cout << "명령을 입력하세요( ADD | SEARCH | EXIT ): ";
		std::getline(std::cin, cmd);
	
		if (cmd == "ADD")
			phoneBook.add();
		if (cmd == "SEARCH")
			phoneBook.search();
		if (std::cin.eof() || cmd == "EXIT")
			break;
		
		std::cout << std::endl;
	}
}