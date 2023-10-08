#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
    // constructor implementation
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {
    // constructor implementation
}

Bureaucrat::Bureaucrat(int grade) : _name("default") {
    // constructor implementation
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    // constructor implementation
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    // copy constructor implementation
    *this = other;
}

Bureaucrat::~Bureaucrat() {
    // destructor implementation
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // assignment operator implementation
        this->_name = other.getName();
        this->_grade = other.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    // output stream operator implementation
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

std::string Bureaucrat::getName(void) const {
    // implementation for getting the bureaucrat's name
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    // implementation for getting the bureaucrat's grade
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    // implementation for incrementing the bureaucrat's grade
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    // implementation for decrementing the bureaucrat's grade
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    // implementation for getting the exception's message
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    // implementation for getting the exception's message
    return "Grade too low";
}