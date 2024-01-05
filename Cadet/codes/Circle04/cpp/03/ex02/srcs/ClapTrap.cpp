#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
name("Default"),
hitPoints(10),
energyPoints(10),
attackDamage(0) {
	std::cout << "ClapTrap Create " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) :
name(name),
hitPoints(10),
energyPoints(10),
attackDamage(0) {
	std::cout << "ClapTrap Create " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
	std::cout << "ClapTrap copy constructor call" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Delete " << name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator call" << std::endl;
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
		std::cout << "ClapTrap ";
		std::cout << name << " is already dead..." << std::endl;
		return ;
	}
	if (!energyPoints) {
		std::cout << "ClapTrap ";
		std::cout << name << " have not enough energy" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target;
	std::cout << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " take " << amount << " damage!" << std::endl;
	if (hitPoints > amount)
		hitPoints -= amount;
	else {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!hitPoints) {
		std::cout << "ClapTrap ";
		std::cout << name << " is already dead..." << std::endl;
		return ;
	}
	if (!energyPoints) {
		std::cout << "ClapTrap ";
		std::cout << name << " have not enough energy" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name;
	std::cout << " recovers by " << amount;
	std::cout << " points." << std::endl;
}

int		ClapTrap::getAttackDamage() {
	return attackDamage;
}
