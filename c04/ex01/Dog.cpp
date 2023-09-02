#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Default Dog";
    this->brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(std::string type)
{
    this->_type = type;
    this->brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    _type = copy.getType();
    this->brain = new Brain(*(copy.brain));
    std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

Dog & Dog::operator=(const Dog &assign)
{
    if (this != &assign){ 
    _type = assign.getType();
    }
    if (this->brain)
		delete brain;
    this->brain = new Brain(*(assign.brain));
    std::cout << "Assignment Operator Dog Called" << std::endl;
    return *this;
}

std::string Dog::getType() const
{
	return (this->_type);
}

void Dog::makeSound() const{
    std::cout << "WuffWuff!" << std::endl;
}

Dog::~Dog()
{
    delete this->brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}
