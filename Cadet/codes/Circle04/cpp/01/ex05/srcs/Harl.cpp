#include "Harl.hpp"

const std::string	Harl::levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
const int			Harl::levelSize = sizeof(levels) / sizeof(levels[0]);

Harl::Harl() {
	harl[0] = &Harl::debug;
	harl[1] = &Harl::info;
	harl[2] = &Harl::warning;
	harl[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::debug() {
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	for (int i = 0; i < levelSize; i++) {
		if (levels[i] == level) {
			(this->*harl[i])();
			return ;
		}
	}
	std::cout << "Out of Range" << std::endl;
}
