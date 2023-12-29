#include "FragTrap.hpp"

using namespace std;

FragTrap::FragTrap(const string& name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	cout << "FragTrap Create " << name << endl;
}

FragTrap::FragTrap() {
	FragTrap("Default");
}

FragTrap::FragTrap(const FragTrap& fragTrap) {
	*this = fragTrap;
}

FragTrap::~FragTrap() {
	cout << "FragTrap Delete " << name << endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void    FragTrap::highFiveGuys() {
	if (!hitPoints) {
		cout << "FragTrap ";
		cout << name << " is already dead..." << endl;
	} else
		cout << "FragTrap " << name << " high five~!" << endl;
}
