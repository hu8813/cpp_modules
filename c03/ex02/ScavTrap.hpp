#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
		ScavTrap(const ScavTrap &copy);
		void attack(const std::string& target);

		// Destructor
		~ScavTrap();
		
		// Operators
		ScavTrap & operator=(const ScavTrap &assign);
		
		// Methods
		void guardGate();
	private:
		
};

#endif