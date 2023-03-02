#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		// Constructors
		HumanB();
		HumanB(const HumanB &copy);
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
		
		// Destructor
		~HumanB();
		
		// Operators
		HumanB & operator=(const HumanB &assign);
		
		// Getters / Setters
		std::string getName() const;
		
	private:
		std::string _name;
		Weapon	*_weapon;
		
};

#endif