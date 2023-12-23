#include "phonebook.hpp"

int main() {
	PhoneBook	phoneBook;
	std::string	cmd;

	while (true) {
		std::cout << "명령을 입력하세요( ADD | SEARCH | EXIT ): ";
		std::getline(std::cin, cmd);
	
		if (cmd == "ADD")
			phoneBook.add();
		if (cmd == "SEARCH") // search시에 인덱스 넘버에 문자를 입력하면 무한루프가 도는 이슈 해결해야함.
			phoneBook.search();
		if (std::cin.eof() || cmd == "EXIT")
			break;
		
		std::cout << std::endl;
	}
}