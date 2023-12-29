#include "ScavTrap.hpp"

using namespace std;

ScavTrap::ScavTrap(const string& name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	cout << "ScavTrap Create " << name << endl;
}

ScavTrap::ScavTrap() {
	ScavTrap("Default");
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
	*this = scavTrap;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap Delete " << name << endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void    ScavTrap::attack(const string& target) {
	if (!hitPoints) {
		cout << "ScavTrap ";
		cout << name << " is already dead..." << endl;
		return ;
	}
	if (!energyPoints) {
		cout << "ScavTrap ";
		cout << name << " have not enough energy" << endl;
		return ;
	}
	energyPoints--;
	cout << "ScavTrap " << name << " attacks " << target;
	cout << ", causing " << attackDamage << " points of damage!" << endl;
}

void	ScavTrap::guardGate() {
	if (!hitPoints) {
		cout << "ScavTrap ";
		cout << name << " is already dead..." << endl;
	} else
		cout << "ScavTrap " << name << " is now in Gate Keeper mode" << endl;
}
