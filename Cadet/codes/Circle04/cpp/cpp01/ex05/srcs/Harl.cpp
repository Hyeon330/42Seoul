#include "Harl.hpp"

using namespace std;

Harl::Harl() {
	harl[0] = &Harl::debug;
	harl[1] = &Harl::info;
	harl[2] = &Harl::warning;
	harl[3] = &Harl::error;
}

Harl::~Harl() {}

void	Harl::debug() {
	cout << "[DEBUG]: I love having extra bacon for my 7XL-double cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void	Harl::info() {
	cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void	Harl::warning() {
	cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void	Harl::error() {
	cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << endl;
}

static int	getHarlNum(string level) {
	const static string str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level == str[i])
			return i;
	}
	return -1;
}

void	Harl::complain(string level) {
	int	harlNum = getHarlNum(level);

	if (harlNum == -1) {
		cout << "Out of Range" << endl;
		return ;
	}
	(this->*harl[harlNum])();
}
