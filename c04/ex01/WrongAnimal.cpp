#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    _type = "Undefined";
    std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    _type = type;
    std::cout << "\e[0;33mDefault Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    _type = copy.getType();
    std::cout << "\e[0;33mCopy Constructor called of WrongAnimal\e[0m" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &assign)
{
    if (this != &assign){ 
    _type = assign.getType();
    }
    std::cout << "Assignment Operator WrongAnimal Called" << std::endl;
    return *this;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(const std::string& type)
{
	_type = type;
}

void WrongAnimal::makeSound() const{
	std::cout << "Default WrongAnimal Song : Wrong Brrrrr!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;31mDestructor called of WrongAnimal\e[0m" << std::endl;
}
