#include "ClapTrap.hpp"

using namespace std;

ClapTrap::ClapTrap() {
	ClapTrap("Default");
}

ClapTrap::ClapTrap(const string& name) :
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	cout << "ClapTrap Create " << name << endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	cout << "ClapTrap Delete " << name << endl;
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
	if (!hitPoints) {
		cout << "ClapTrap ";
		cout << name << " is already dead..." << endl;
		return ;
	}
	if (!energyPoints) {
		cout << "ClapTrap ";
		cout << name << " have not enough energy" << endl;
		return ;
	}
	energyPoints--;
	cout << "ClapTrap " << name << " attacks " << target;
	cout << ", causing " << attackDamage << " points of damage!" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	cout << "ClapTrap " << name << " take " << amount << " damage!" << endl;
	if (hitPoints > amount)
		hitPoints -= amount;
	else {
		hitPoints = 0;
		cout << "ClapTrap " << name << " is dead" << endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!hitPoints) {
		cout << "ClapTrap ";
		cout << name << " is already dead..." << endl;
		return ;
	}
	if (!energyPoints) {
		cout << "ClapTrap ";
		cout << name << " have not enough energy" << endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	cout << "ClapTrap " << name;
	cout << " recovers by " << amount;
	cout << " points." << endl;
}

int		ClapTrap::getAttackDamage() {
	return attackDamage;
}
