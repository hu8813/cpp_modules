#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		// Constructors
		HumanA();
		HumanA(std::string name);
		HumanA(std::string name, Weapon &weapon);
		void attack();
		
		// Destructor
		~HumanA();
		
		// Getters / Setters
		std::string getName() const;
		
	private:
		std::string _name;
		Weapon	*_weapon;
		
};
