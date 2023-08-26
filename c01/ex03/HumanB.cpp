#include "HumanB.hpp"

// Constructors
HumanB::HumanB()
{
	_name = "";
	_weapon = NULL;
	std::cout << "\e[0;33mDefault Constructor called of HumanB\e[0m" << std::endl;
}

HumanB::HumanB(const HumanB &copy)
{
	_name = copy.getName();
	_weapon = copy._weapon;
	std::cout << "\e[0;33mCopy Constructor called of HumanB\e[0m" << std::endl;
}

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	std::cout << "\e[0;33mFields Constructor called of HumanB\e[0m" << std::endl;
}

void HumanB::attack()
{
	if (_weapon != NULL)
	{
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
		return ;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

// Destructor
HumanB::~HumanB()
{
	std::cout << "\e[0;31mDestructor called of HumanB\e[0m" << std::endl;
}

// Getters / Setters
std::string HumanB::getName() const
{
	return (_name);
}
