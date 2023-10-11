#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // Create some forms
    PresidentialPardonForm presidentialForm("Marx");
    RobotomyRequestForm robotomyForm("Ehab");
    ShrubberyCreationForm shrubberyForm("Deyan");
    Bureaucrat kaya("Kaya", 1);
    // Try to execute the forms before they are signed

    kaya.executeForm(presidentialForm);

    Bureaucrat valentin("Valentin", 1);
    valentin.signForm(presidentialForm);
    valentin.executeForm(presidentialForm);
    
    kaya.signForm(robotomyForm);
    kaya.executeForm(robotomyForm);

    // Sign the forms
    Bureaucrat enes("Enes", 50);
    enes.signForm(presidentialForm);
    enes.signForm(robotomyForm);
    enes.signForm(shrubberyForm);
    enes.executeForm(presidentialForm);
    enes.executeForm(robotomyForm);
    enes.executeForm(shrubberyForm);

    return 0;
}
