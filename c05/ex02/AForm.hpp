#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {    
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& other);
        virtual ~AForm();
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);

        virtual void execute(const Bureaucrat& executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& aform);
