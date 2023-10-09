
#include "Form.hpp"

Form::Form(std::string name = "default", int gradeToSign = 1, int gradeToExecute = 1)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    _isSigned = false;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    this->_isSigned = true;
}

Form::Form(const Form& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form& other)
{
    this->_isSigned = other._isSigned;
    return (*this);
}

Form::~Form()
{
}

std::string Form::getName(void) const
{
    return this->_name;
}

int Form::getGradeToSign(void) const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const
{
    return this->_gradeToExecute;
}

bool Form::getIsSigned(void) const
{
    return this->_isSigned;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ".";
    return os;
}