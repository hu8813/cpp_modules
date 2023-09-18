#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	// Constructors
	FragTrap();
	FragTrap(std::string name);
	FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
	FragTrap(const FragTrap &copy);

	// Destructor
	~FragTrap();

	// Operators
	FragTrap &operator=(const FragTrap &assign);

	// Methods
	void highFivesGuys(void);
	void attack(const std::string &target);

private:
};
