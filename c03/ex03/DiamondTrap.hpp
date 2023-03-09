#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
		DiamondTrap(const DiamondTrap &copy);
		
		// Destructor
		~DiamondTrap();
		
		// Operators
		DiamondTrap & operator=(const DiamondTrap &assign);

		// Getters / Setters
		std::string getName() const;
		void setName(std::string name);
		void whoAmI();
		using ScavTrap::attack;
		
	private:
		std::string _name;
};

#endif