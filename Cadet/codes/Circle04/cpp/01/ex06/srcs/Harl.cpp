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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	int	harlNum = -1;

	for (int i = 0; i < levelSize && harlNum < 0; i++) {
		if (levels[i] == level)
			harlNum = i;
	}
	switch (harlNum) {
		case 0:
			(this->*harl[0])();
			break;
		case 1:
			(this->*harl[1])();
			break;
		case 2:
			(this->*harl[2])();
			break;
		case 3:
			(this->*harl[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
