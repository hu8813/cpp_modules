#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
    // constructor
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {
    // constructor
}

Bureaucrat::Bureaucrat(int grade) : _name("default") {
    // constructor
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    // constructor
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

void Bureaucrat::signForm(Form &form) const {
    try {
        form.beSigned(*this);
        std::cout << "\033[32m" << this->_name << " signed " << form.getName() << "\033[0m" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "\033[31m" << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
    }
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
}

void Bureaucrat::decrementGrade() {
    // for decrementing the bureaucrat's grade
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    // for getting the exception's message
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    // for getting the exception's message
    return "Grade too low";
}