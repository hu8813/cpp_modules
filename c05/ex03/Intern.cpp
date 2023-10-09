#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &) {
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm *form = NULL;

    if (formName == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
        std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;
    } else if (formName == "robotomy request") {
        form = new RobotomyRequestForm(target);
        std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;
    } else if (formName == "presidential pardon") {
        form = new PresidentialPardonForm(target);
        std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31mIntern could not create " << formName << "\033[0m" << std::endl;
    }

    return form;
}
