#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
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
		
		// Operators
		HumanA & operator=(const HumanA &assign);
		
		// Getters / Setters
		std::string getName() const;
		
	private:
		std::string _name;
		Weapon	*_weapon;
		
};

#endif