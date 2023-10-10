#include "Intern.hpp"
#include "AForm.hpp"

#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    delete rrf;

    // Test creating a form that the intern knows how to create
    AForm* srf;
    srf = someRandomIntern.makeForm("shrubbery creation", "Bob");
    std::cout << *srf << std::endl;
    delete srf;

    // Test creating a form that the intern doesn't know how to create
    AForm* nrf;
    nrf = someRandomIntern.makeForm("nonexistent form", "Alice");
    if (nrf == NULL) {
        std::cout << "Intern doesn't know how to create nonexistent form" << std::endl;
    } else {
        std::cout << "Unexpected form created: " << *nrf << std::endl;
        delete nrf;
    }

    // Test creating a form with an empty name
    AForm* erf;
    erf = someRandomIntern.makeForm("", "Charlie");
    if (erf == NULL) {
        std::cout << "Intern doesn't know how to create form with empty name" << std::endl;
    } else {
        std::cout << "Unexpected form created: " << *erf << std::endl;
        delete erf;
    }

    // Test creating a form with an empty target
    AForm* trf;
    trf = someRandomIntern.makeForm("presidential pardon", "");
    if (trf == NULL) {
        std::cout << "Intern doesn't know how to create form with empty target" << std::endl;
    } else {
        std::cout << "Unexpected form created: " << *trf << std::endl;
        delete trf;
    }

    return 0;
}