#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    _type = "Undefined";
    std::cout << "\e[0;33mDefault Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    _type = type;
    std::cout << "\e[0;33mDefault Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    _type = copy.getType();
    std::cout << "\e[0;33mCopy Constructor called of AAnimal\e[0m" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal &assign)
{
    if (this != &assign){ 
    _type = assign.getType();
    }
    std::cout << "\e[0;33mCopy Assignment Operator called of AAnimal\e[0m" << std::endl;
    return *this;
}

std::string AAnimal::getType() const
{
	return _type;
}

void AAnimal::makeSound() const{
	std::cout << "Default AAnimal Song : Brrrrr!" << std::endl;
}

void AAnimal::setType(const std::string& type)
{
	_type = type;
}

AAnimal::~AAnimal()
{
	std::cout << "\e[0;31mDestructor called of AAnimal\e[0m" << std::endl;
}
