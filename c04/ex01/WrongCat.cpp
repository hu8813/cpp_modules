#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "Undefined";
    this->brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    _type = type;
    this->brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    _type = copy.getType();
    this->brain = new Brain(*(copy.brain));
    std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &assign)
{
    if (this != &assign){ 
    _type = assign.getType();
    }
    if (this->brain)
		delete brain;
    this->brain = new Brain(*(assign.brain));
    std::cout << "Assignment Operator WrongCat Called" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const{
    WrongAnimal::makeSound();
    //std::cout << "Default Wrong Cat Song: Wrong Miaww!" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->_type);
}

WrongCat::~WrongCat()
{
    delete this->brain;
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}
