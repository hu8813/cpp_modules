#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("Robotomy Request AForm", 72, 45),
    _target(target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other),
    _target(other._target)
{
    std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
    {
        throw GradeTooLowException();
    }
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << _target << " has failed." << std::endl;
    }
}
