#include "DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap()
{
	this->_name = "noName";
	std::cout << "\e[0;33mDefault Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : FragTrap(copy), ScavTrap(copy)
{
	this->_name = copy.getName();
	std::cout << "\e[0;33mCopy Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	this->setHitPoints(FragTrap::getHitPoints);
	this->_energyPoints = ScavTrap::getEnergyPoints;
	this->_attackDamage = FragTrap::getAttackDamage;
	std::cout << "\e[0;33mFields Constructor called of DiamondTrap\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name, int hitPoints, int energyPoints, int attackDamage)
{
	this->_name = name;
	this->setHitPoints(hitPoints);
	this->setEnergyPoints(energyPoints);
	this->setAttackDamage(attackDamage);
	std::cout << "\e[0;33mFields Constructor called of DiamondTrap\e[0m" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\e[0;31mDestructor called of DiamondTrap\e[0m" << std::endl;
}


// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	this->_name = assign.getName();
	this->setHitPoints(assign.getHitPoints());
	this->setEnergyPoints(assign.getEnergyPoints());
	this->setAttackDamage(assign.getAttackDamage());
	std::cout << "\e[0;33mAssignation operator called of DiamondTrap\e[0m" << std::endl;
	return *this;
}

// Getters / Setters
void DiamondTrap::setName(std::string name)
{
	_name = name;
}

std::string DiamondTrap::getName() const
{
	return _name;
}

// Methods
void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << _ClapTrap::getName() << std::endl;
}