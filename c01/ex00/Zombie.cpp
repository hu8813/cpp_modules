#include "Zombie.hpp"

// Constructors
Zombie::Zombie()
{
	_name = "Undefined";
	std::cout << "\e[0;33mDefault Constructor called of Zombie: " << _name << "\e[0m" << std::endl;
}

Zombie::Zombie(const std::string &name) {
	this->_name = name;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(const Zombie &copy)
{
	_name = copy.getName();
	std::cout << "\e[0;33mCopy Constructor called of Zombie: " << _name << "\e[0m" << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << "\e[0;31mDestructor called of Zombie: " << _name << "\e[0m" << std::endl;
}


// Getters / Setters
std::string Zombie::getName() const
{
	return _name;
}
