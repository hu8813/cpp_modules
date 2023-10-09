#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
public:
    Bureaucrat(std::string name = "default");
    Bureaucrat(int grade = 150);
    Bureaucrat(void);
    Bureaucrat(std::string name = "default", int grade = 150);
    Bureaucrat(const Bureaucrat& other);
    virtual ~Bureaucrat();
    signForm();
    Bureaucrat& operator=(const Bureaucrat& other);

    std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

