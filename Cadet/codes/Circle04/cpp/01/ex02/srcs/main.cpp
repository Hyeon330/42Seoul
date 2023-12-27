#include <iostream>

int main() {
	std::string	str = "HI This Is Brain";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "================ memory =================" << std::endl;

	std::cout << "str memory: " << &str << std::endl;
	std::cout << "PTR memory: " << stringPTR << std::endl;
	std::cout << "REF memory: " << &stringREF << std::endl;

	std::cout << "================ value ==================" << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;
}