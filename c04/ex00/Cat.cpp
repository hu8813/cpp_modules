#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Default Cat";
    std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(std::string type)
{
    this->_type = type;
    std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    _type = copy.getType();
    std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat &assign)
{
    if (this != &assign){ 
    _type = assign.getType();
    }
    std::cout << "Assignment Operator Cat Called" << std::endl;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Miaww!" << std::endl;
}

std::string Cat::getType() const
{
	return (this->_type);
}

Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}
