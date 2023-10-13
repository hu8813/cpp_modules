#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name = "default", int grade = 150);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

