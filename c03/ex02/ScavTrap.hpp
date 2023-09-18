#pragma once

#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	// Constructors
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
	ScavTrap(const ScavTrap &copy);

	// Destructor
	~ScavTrap();

	// Operators
	ScavTrap &operator=(const ScavTrap &assign);

	// Methods
	void guardGate();
	void attack(const std::string &target);

private:
};
