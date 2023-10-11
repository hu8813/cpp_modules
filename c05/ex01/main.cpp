#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    // Create a bureaucrat with a grade of 6
    Bureaucrat b1("Marx", 6);
    std::cout << b1 << std::endl;

    // create a form
    Form f1("Form1", 5, 1);
    std::cout << f1 << std::endl;

    b1.signForm(f1);
    std::cout << f1 << std::endl;
    
    // Try to increment the grade of b1
    try {
        b1.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << b1 << std::endl;

    b1.signForm(f1);
    std::cout << f1 << std::endl;

    // Create a bureaucrat with a grade of 150
    Bureaucrat b2("Ehab", 150);
    std::cout << b2 << std::endl;

    // Try to create a form with a grade requirement of 0
    try {
        Form f2("Form2", 0, 1);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Try to create a form with a signing grade requirement of 151
    try {
        Form f3("Form3", 5, 151);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Try to sign a form with a bureaucrat with a grade of 150
    try {
        b2.signForm(f1);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Create a bureaucrat with a grade of 50
    Bureaucrat b3("Deyan", 50);
    std::cout << b3 << std::endl;

    // create a form with a grade requirement of 50 and a signing grade requirement of 25
    Form f4("Form4", 50, 25);
    std::cout << f4 << std::endl;

    // Try to sign a form with a bureaucrat with a grade of 26
    try {
        Bureaucrat b4("Kaya", 26);
        std::cout << b4 << std::endl;
        b4.signForm(f4);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Try to sign a form with a bureaucrat with a grade of 50
    try {
        b3.signForm(f4);
        std::cout << f4 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}