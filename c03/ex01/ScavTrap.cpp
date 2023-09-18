#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Constructors
ScavTrap::ScavTrap():_name("noName"),_hitPoints(100),_energyPoints(50),_attackDamage(20)
{
	std::cout << "\e[0;32mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap():_name(name),_hitPoints(100),_energyPoints(50),_attackDamage(20)
{
	std::cout << "\e[0;32mName Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string	name, int hitPoints, int energyPoints, int attackDamage):_name(name),_hitPoints(hitPoints),_energyPoints(energyPoints),_attackDamage(attackDamage)
{
	std::cout << "\e[0;32mFields Constructor called of ScavTrap\e[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "\e[0;32mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	this->_name = assign.getName();
	this->_energyPoints = assign.getEnergyPoints();
	this->_hitPoints = assign.getHitPoints();
	this->_attackDamage = assign.getAttackDamage();
	std::cout << "\e[0;32mScavTrap\e[0m " << this->getName() << " copy assignment called" << std::endl;
	return *this;
}

// Methods
void ScavTrap::guardGate()
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
		std::cout << "\e[0;32mScavTrap\e[0m " << "\e[0;33m" << this->getName()<< "\e[0m"  << " has entered in Gate keeper mode" << std::endl;
	else
		std::cout << "\e[0;32mScavTrap\e[0m " << "\e[0;33m" << this->getName()<< "\e[0m"  << " can not enter in Gate keeper mode (no Energy/Hitpoints)" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (ClapTrap::getHitPoints() <= 0)
	{
		std::cout << "\e[0;32mScavTrap\e[0m " << "\e[0;33m" << ClapTrap::getName() << "\e[0m" << " has no hitPoints (dead)!" << std::endl;
		return ;
	}
	else if (ClapTrap::getEnergyPoints() <= 0)
	{
		std::cout << "\e[0;32mScavTrap\e[0m " << "\e[0;33m" << ClapTrap::getName() << "\e[0m" << " has no energy/hitpoints to attack!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "\e[0;32mScavTrap\e[0m " << "\e[0;33m" << ClapTrap::getName() << "\e[0m" << " attacks " << target << ", causing " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
}
