
#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap() : ClapTrap("noName", 100, 100, 30)
{
	std::cout << "\e[0;35mDefault Constructor called of FragTrap\e[0m"
			  << " HP: " << _hitPoints << ", EP: " << _energyPoints << ", AP: " << _attackDamage << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "\e[0;35mDefault Constructor called of FragTrap\e[0m"
			  << " HP: " << _hitPoints << ", EP: " << _energyPoints << ", AP: " << _attackDamage << std::endl;
}

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "\e[0;35mFields Constructor called of FragTrap\e[0m"
			  << " HP: " << _hitPoints << ", EP: " << _energyPoints << ", AP: " << _attackDamage << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap()
{
	*this = copy;
	std::cout << "\e[0;35mCopy Constructor called of FragTrap\e[0m" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
}

// Operators
FragTrap &FragTrap::operator=(const FragTrap &assign)
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
		std::cout << "\e[0;31mFragTrap: " << ClapTrap::getName() << "\e[0m"
				  << " can't high five. No energy/hitPoints (dead)!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (ClapTrap::getHitPoints() <= 0)
	{
		std::cout << "\e[0;32mFragTrap\e[0m "
				  << "\e[0;33m" << ClapTrap::getName() << "\e[0m"
				  << " has no hitPoints (dead)!" << std::endl;
		return;
	}
	else if (ClapTrap::getEnergyPoints() <= 0)
	{
		std::cout << "\e[0;32mFragTrap\e[0m "
				  << "\e[0;33m" << ClapTrap::getName() << "\e[0m"
				  << " has no energy/hitpoints to attack!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "\e[0;32mFragTrap\e[0m "
			  << "\e[0;33m" << ClapTrap::getName() << "\e[0m"
			  << " attacks " << target << ", causing " << ClapTrap::getAttackDamage() << " points of damage!" << std::endl;
}
