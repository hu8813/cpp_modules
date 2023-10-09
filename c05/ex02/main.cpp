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
    // Try to execute the forms before they are signed
    try {
        presidentialForm.execute(Bureaucrat("Kaya", 1));
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    Bureaucrat bureaucrat2("Valentin", 1);
    try {
        bureaucrat2.signForm(robotomyForm);
        robotomyForm.execute(bureaucrat2);
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        shrubberyForm.execute(Bureaucrat("Ezgi", 1));
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Sign the forms
    Bureaucrat bureaucrat("Francis", 50);
    try {
        bureaucrat.signForm(presidentialForm);
        bureaucrat.signForm(robotomyForm);
        bureaucrat.signForm(shrubberyForm);
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Try to execute the forms again after they are signed
    try {
        presidentialForm.execute(Bureaucrat("Bob", 1));
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        robotomyForm.execute(Bureaucrat("Bob", 1));
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        shrubberyForm.execute(Bureaucrat("Bob", 1));
    } catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
