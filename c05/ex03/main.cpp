#include "Intern.hpp"
#include "AForm.hpp"

#include <iostream>

int main() {

    Bureaucrat kaya("Kaya", 1);

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    kaya.signForm(*rrf);
    kaya.executeForm(*rrf);
    delete rrf;

    // Test creating a form that the intern knows how to create
    AForm* srf;
    srf = someRandomIntern.makeForm("shrubbery creation", "Bob");
    std::cout << *srf << std::endl;
    kaya.signForm(*srf);
    kaya.executeForm(*srf);
    delete srf;

    // Test creating a form that the intern doesn't know how to create
    AForm* nrf;
    nrf = someRandomIntern.makeForm("nonexistent form", "Alice");
    if (nrf != NULL)
    {
    try
    {
        kaya.signForm(*nrf);
        kaya.executeForm(*nrf);
        delete nrf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    }

    // Test creating a form with an empty name
    AForm* erf;
    erf = someRandomIntern.makeForm("", "Charlie");
    if (erf != NULL)
    {
    try
    {
        kaya.signForm(*erf);
        kaya.executeForm(*erf);
        delete erf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    }

    // Test creating a form with an empty target
    AForm* trf;
    trf = someRandomIntern.makeForm("presidential pardon", "");
    if (trf != NULL)
    {
    try
    {
        kaya.signForm(*trf);
        kaya.executeForm(*trf);
        delete trf;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    }

    return 0;
}