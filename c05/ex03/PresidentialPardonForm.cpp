#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon AForm", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon AForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        throw GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
