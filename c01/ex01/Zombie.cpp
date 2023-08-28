#include "Zombie.hpp"

// Constructors
Zombie::Zombie()
{
	this->_name = "Undefined";
	std::cout << "\e[0;33mDefault Constructor called of Zombie: " << _name << "\e[0m" << std::endl;
}

Zombie::Zombie(const std::string &name) {
	this->_name = name;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
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

void Zombie::setName(const std::string &name) 
{
	this->_name = name;
}