#include "Animal.hpp"

Animal::Animal()
{
    _type = "Undefined";
    std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(std::string type)
{
    _type = type;
    std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    _type = copy.getType();
    std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}

Animal & Animal::operator=(const Animal &assign)
{
    _type = assign.getType();
    std::cout << "\e[0;33mCopy Assignment Operator called of Animal\e[0m" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const{
	std::cout << "Default Animal Song : Brrrrr!" << std::endl;
}

void Animal::setType(const std::string& type)
{
	_type = type;
}

Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}

Brain *Animal::getBrain()
{
    return NULL;
}