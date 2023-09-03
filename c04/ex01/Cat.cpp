#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Default Cat";
    this->_brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(std::string type)
{
    this->_type = type;
    this->_brain = new Brain();
    std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    _type = copy.getType();
    this->_brain = new Brain(*(copy._brain));
    std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

Cat & Cat::operator=(const Cat &assign)
{
    _type = assign.getType();
    if (this->_brain)
		delete _brain;
    this->_brain = new Brain(*(assign._brain));
    std::cout << "Assignment Operator Cat Called" << std::endl;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "\e[0;32mMiaww!\e[0m" << std::endl;
}

std::string Cat::getType() const
{
	return (this->_type);
}

Cat::~Cat()
{
    delete this->_brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

Brain *Cat::getBrain(void)
{
    return (this->_brain);
}
