#include "Bureaucrat.hpp"

int main() {
    // Create a bureaucrat with a grade of 1
    Bureaucrat b1("Marx", 1);
    std::cout << b1 << std::endl;

    // Try to increment the grade of b1
    try {
        b1.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b1 << std::endl;

    try {
        b1.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b1 << std::endl;

    // Create a bureaucrat with a grade of 150
    Bureaucrat b2("Ehab", 150);
    std::cout << b2 << std::endl;

    // Try to decrement the grade of b2
    try {
        b2.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b2 << std::endl;

    try {
        b2.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b2 << std::endl;

    return 0;
}
