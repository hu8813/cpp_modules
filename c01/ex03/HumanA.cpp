#include "HumanA.hpp"

// Constructors
HumanA::HumanA()
{
	_name = "Default Name";
	_weapon->setType("Default Weapon");
	std::cout << "\e[0;33mDefault Constructor called of HumanA\e[0m" << std::endl;
}

HumanA::HumanA(std::string name)
{
	_name = name;
	_weapon->setType("Default Weapon");
	std::cout << "\e[0;33mFields Constructor called of HumanA\e[0m" << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	_name = name;
	_weapon = &weapon;
	std::cout << "\e[0;33mFields Constructor called of HumanA\e[0m" << std::endl;
}

void HumanA::attack()
{
	if (_weapon != NULL)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

// Destructor
HumanA::~HumanA()
{
	std::cout << "\e[0;31mDestructor called of HumanA\e[0m" << std::endl;
}

// Getters / Setters
std::string HumanA::getName() const
{
	return (_name);
}
