#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	ClapTrap::name = "Default_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Create " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	name(name) {
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap Create " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) {
	std::cout << "DiamonTrap copy constructor call" << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Delete " << name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignment operator call" << std::endl;
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
	std::cout << "ClapTrap name is " << ClapTrap::name << std::endl;
	std::cout << "DiamondTrap name is " << this->name << std::endl;
}
