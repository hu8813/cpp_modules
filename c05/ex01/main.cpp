#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Create a bureaucrat with a grade of 1
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
        std::cerr << e.what() << std::endl;
    }
    std::cout << b1 << std::endl;

    b1.signForm(f1);
    std::cout << f1 << std::endl;


    return 0;
}
