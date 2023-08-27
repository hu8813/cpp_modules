#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		// Constructors
		HumanA();
		HumanA(const HumanA &copy);
		HumanA(std::string name);
		HumanA(std::string name, Weapon &weapon);
		void attack();
		void setWeapon(Weapon &weapon);
		
		// Destructor
		~HumanA();
		
		// Getters / Setters
		std::string getName() const;
		
	private:
		std::string _name;
		Weapon	*_weapon;
		
};

#endif