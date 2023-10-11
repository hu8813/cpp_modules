#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
    // default constructor
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {
    // name constructor
}

Bureaucrat::Bureaucrat(int grade) : _name("default") {
    // int constructor
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    // name, int constructor
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    // copy constructor
    *this = other;
}

Bureaucrat::~Bureaucrat() {
    // destructor
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // assignment operator
        this->_name = other.getName();
        this->_grade = other.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    // output stream operator
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

std::string Bureaucrat::getName(void) const {
    // for getting the bureaucrat's name
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    // for getting the bureaucrat's grade
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    // for incrementing the bureaucrat's grade
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
    std::cout << _name << " Grade incremented to: " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() {
    // for decrementing the bureaucrat's grade
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
    std::cout << _name << " Grade decremented to: " << _grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    // for getting the exception's message
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    // for getting the exception's message
    return "Grade too low";
}
