#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Create " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Create " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
	std::cout << "ScavTrap copy constructor call" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Delete " << name << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator call" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void    ScavTrap::attack(const std::string& target) {
	std::cout << "ScavTrap " << name;
	if (!hitPoints) {
		std::cout << " is already dead..." << std::endl;
		return ;
	}
	if (!energyPoints) {
		std::cout << " have not enough energy" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << " attacks " << target;
	std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name;
	if (!hitPoints) {
		std::cout << " is already dead..." << std::endl;
		return ;
	}
	if (!energyPoints) {
		std::cout << " have not enough energy" << std::endl;
		return ;
	}
	std::cout << " is now in Gate Keeper mode" << std::endl;
}
