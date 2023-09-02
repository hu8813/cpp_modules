#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Default Cat";
    this->brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(std::string type)
{
    this->_type = type;
    this->brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    _type = copy.getType();
    this->brain = new Brain(*(copy.brain));
    std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat &assign)
{
    if (this != &assign){ 
    _type = assign.getType();
    }
    if (this->brain)
		delete brain;
    this->brain = new Brain(*(assign.brain));
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
    delete this->brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}
