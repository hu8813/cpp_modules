#pragma once

#include <iostream>
#include "Weapon.hpp"

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
		
	
		// Getters / Setters
		std::string getName() const;
		
	private:
		std::string _name;
		Weapon	*_weapon;
		
};
