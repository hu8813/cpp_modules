
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap()
{
	this->_name = "noName";
	std::cout << "\e[0;35mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string	name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "\e[0;35mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage)
{
	this->_name = name;
	this->_hitPoints = hitPoints;
	this->_energyPoints = energyPoints;
	this->_attackDamage = attackDamage;
	std::cout << "\e[0;35mFields Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	_name = copy.getName();
	_hitPoints = copy.getHitPoints();
	_energyPoints = copy.getEnergyPoints();
	_attackDamage = copy.getAttackDamage();
	std::cout << "\e[0;35mCopy Constructor called of FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	this->_name = assign.getName();
	this->_energyPoints = assign.getEnergyPoints();
	this->_hitPoints = assign.getHitPoints();
	this->_attackDamage = assign.getAttackDamage();
	std::cout << "FragTrap " << this->getName() << " copy assignment called" << std::endl;
	return *this;
}

// Methods
void FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
		std::cout << "\e[0;31mFragTrap: High fives guys!\e[0m" << std::endl;
	else
		std::cout << "\e[0;31mFragTrap: " << ClapTrap::getName() << "\e[0m" << " can't high five. No energy/hitPoints (dead)!" << std::endl;
}

