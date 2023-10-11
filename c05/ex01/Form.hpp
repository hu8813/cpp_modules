#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    ~Form();
    std::string getName(void) const;
    int getGradeToSign(void) const;
    int getGradeToExecute(void) const;
    bool getIsSigned(void) const;
    void beSigned(const Bureaucrat& bureaucrat);
    Form(const Form& other);
    Form& operator=(const Form& other);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const Form& form);