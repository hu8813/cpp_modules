
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap()
{
	this->setName("noName");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string	name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage)
{
	this->setName(name);
	this->setHitPoints(hitPoints);
	this->setEnergyPoints(energyPoints);
	this->setAttackDamage(attackDamage);
	std::cout << "\e[0;33mFields Constructor called of FragTrap\e[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}


// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}


// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	(void) assign;
	return *this;
}

// Methods
void FragTrap::highFivesGuys(void)
{
	std::cout << "\e[0;33mHigh fives guys!\e[0m" << std::endl;
}