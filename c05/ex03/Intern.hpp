#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        virtual ~Intern();

        Intern& operator=(const Intern& other);

        AForm* makeForm(const std::string &formName, const std::string &target);

    private:
        AForm* createShrubberyCreationForm(const std::string& target) const;
        AForm* createRobotomyRequestForm(const std::string& target) const;
        AForm* createPresidentialPardonForm(const std::string& target) const;
};

#endif
