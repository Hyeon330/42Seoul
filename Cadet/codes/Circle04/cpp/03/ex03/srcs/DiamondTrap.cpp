#include "DiamondTrap.hpp"

using namespace std;

DiamondTrap::DiamondTrap(const string& name) :
	name(name) {
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	cout << "DiamondTrap Create " << name << endl;
}

DiamondTrap::DiamondTrap() {
	DiamondTrap("Default");
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap Delete " << name << endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		name = other.name;
		ClapTrap::name = other.ClapTrap::name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void	DiamondTrap::whoAmI() {
	cout << "ClapTrap name is " << ClapTrap::name << endl;
	cout << "DiamondTrap name is " << this->name << endl;
}
