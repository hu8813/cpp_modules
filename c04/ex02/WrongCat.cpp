#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "Undefined";
    std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    _type = type;
    std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
    _type = copy.getType();
    std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &assign)
{
    _type = assign.getType();
    std::cout << "Assignment Operator WrongCat Called" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Default Wrong Cat Song: Wrong Miaww!" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->_type);
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}
