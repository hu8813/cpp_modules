#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Default Dog";
    std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(std::string type)
{
    this->_type = type;
    std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    _type = copy.getType();
    std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

Dog & Dog::operator=(const Dog &assign)
{
    _type = assign.getType();
    std::cout << "Assignment Operator Dog Called" << std::endl;
    return *this;
}

std::string Dog::getType() const
{
	return (this->_type);
}

void Dog::makeSound() const{
    std::cout << "\e[0;34mWuffWuff!\e[0m" << std::endl;
}

Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}
