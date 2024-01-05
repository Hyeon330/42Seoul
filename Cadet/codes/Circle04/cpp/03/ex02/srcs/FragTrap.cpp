#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Create " << name << std::endl;
}

FragTrap::FragTrap(const std::string& name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap Create " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) {
	std::cout << "FragTrap copy constructor call" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Delete " << name << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator call" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void    FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << name;
	if (!hitPoints) {
		std::cout << " is already dead..." << std::endl;
		return ;
	}
	if (!energyPoints) {
		std::cout << " have not enough energy" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << " high five!~" << std::endl;
}
