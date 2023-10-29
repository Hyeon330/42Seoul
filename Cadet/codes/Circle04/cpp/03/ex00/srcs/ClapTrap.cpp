#include "ClapTrap.hpp"

using namespace std;

ClapTrap::ClapTrap() {
	cout << "ClapTrap ";
	cout << "Create a " << name << endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	cout << "ClapTrap ";
	cout << "Delete " << name << endl;
}

ClapTrap::ClapTrap(const string& name) :
name(name),
hitPoints(10),
energyPoints(10),
attackDamage(0) {
	cout << "ClapTrap ";
	cout << "Create a " << name << endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target) {
	if (!energyPoints) {
		cout << "You've not enough energy" << endl;
		return ;
	}
	energyPoints--;
	cout << "ClapTrap " << name;
	cout << " attacks " << target;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	cout << ", causing " << amount << " points of damage!" << endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!energyPoints) {
		cout << "You've not enough energy" << endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	cout << "ClapTrap " << name;
	cout << " recovers by " << amount;
	cout << " points." << endl;
}
