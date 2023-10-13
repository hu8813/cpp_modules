#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
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
    std::cout << "\033[1;31mBureaucrat " << _name << " destroyed\033[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // assignment operator
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

void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << "\033[32m" << this->_name << " executed " << form.getName() << "\033[0m" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\033[31m" << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
    }
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

void Bureaucrat::signForm(AForm &form) const {
    try {
            form.beSigned(*this);
            std::cout << "\033[32m" << this->_name << " signed " << form.getName() << "\033[0m" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[31m" << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
        }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    // for getting the exception's message
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    // for getting the exception's message
    return "Grade too low";
}
