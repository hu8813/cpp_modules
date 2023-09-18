#pragma once

#include <iostream>

class ClapTrap
{
public:
	// Constructors
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);

	// Destructor
	~ClapTrap();

	// Operators
	ClapTrap &operator=(const ClapTrap &assign);

	// Getters / Setters
	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};
