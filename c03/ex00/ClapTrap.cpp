#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _name("noName"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\e[0;33mName Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "\e[0;33mFields Constructor called of ClapTrap\e[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
}

// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	_name = assign.getName();
	_hitPoints = assign.getHitPoints();
	_energyPoints = assign.getEnergyPoints();
	_attackDamage = assign.getAttackDamage();
	return *this;
}

// Getters / Setters
std::string ClapTrap::getName() const
{
	return _name;
}
int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}
int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}
int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

// Methods
void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " has no hitPoints (dead)!" << std::endl;
		return;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " has no energy/hitpoints to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "\e[0;34mClapTrap\e[0m "
			  << "\e[0;33m" << _name << "\e[0m"
			  << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " has no hitPoints (dead)!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " has no energy to take damage!" << std::endl;
	else if (static_cast<int>(this->_hitPoints - amount) <= this->_hitPoints && (this->_hitPoints - amount) > 0)
	{
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
	else if (static_cast<int>(this->_hitPoints - amount) <= this->_hitPoints && this->_hitPoints - amount <= 0)
	{
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " takes " << amount << " points of damage and died!" << std::endl;
		this->_hitPoints -= amount;
	}
	else if (static_cast<int>(this->_hitPoints - amount) > this->_hitPoints)
		std::cout << "\e[0;34mOVERFLOW! ClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " has no hitPoints (dead)!" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " has no energy/hitPoints to repair!" << std::endl;
	else if (static_cast<int>(this->_hitPoints + amount) >= this->_hitPoints)
	{
		this->_energyPoints--;
		this->_hitPoints = this->_hitPoints + amount;
		std::cout << "\e[0;34mClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " is repaired by " << amount << " points!" << std::endl;
	}
	else
		std::cout << "\e[0;34mOVERFLOW! ClapTrap\e[0m "
				  << "\e[0;33m" << _name << "\e[0m"
				  << " cannot be repaired" << std::endl;
}
