#include "Weapon.hpp"

// Constructors
Weapon::Weapon()
{
	_type = "";
	std::cout << "\e[0;33mDefault Constructor called of Weapon\e[0m" << std::endl;
}

Weapon::Weapon(std::string type)
{
	_type = type;
	std::cout << "\e[0;33mFields Constructor called of Weapon\e[0m" << std::endl;
}


// Destructor
Weapon::~Weapon()
{
	std::cout << "\e[0;31mDestructor called of Weapon\e[0m" << std::endl;
}


// Getters / Setters
std::string Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

