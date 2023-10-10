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

 AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
        static const char* validFormNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

        for (int i = 0; i < 3; ++i) {
            if (formName != "" && target != "" && formName == validFormNames[i]) {
                switch (i)
                {
                case 0:
                    std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;
                    return new ShrubberyCreationForm(target);
                    break;
                
                case 1:
                    std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;
                    return new RobotomyRequestForm(target);
                    break;
                case 2:
                    std::cout << "\033[32mIntern creates " << formName << "\033[0m" << std::endl;
                    return new PresidentialPardonForm(target);
                    break;
                }
            }
        }

        std::cout << "\033[31mIntern could not create " << formName << "\033[0m" << std::endl;
        return NULL;
    }
