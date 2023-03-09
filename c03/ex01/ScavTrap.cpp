#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
ScavTrap::ScavTrap()
{
	this->setName("noName");
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name, int hitPoints, int energyPoints, int attackDamage)
{
	this->setName(name);
	this->setHitPoints(hitPoints);
	this->setEnergyPoints(energyPoints);
	this->setAttackDamage(attackDamage);
	std::cout << "\e[0;33mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}


// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}


// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	(void) assign;
	return *this;
}

// Methods
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << std::endl;
}
