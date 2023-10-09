#include "Bureaucrat.hpp"

int main() {
    // Create a bureaucrat with a grade of 1
    Bureaucrat b1("Marx", 1);
    std::cout << b1 << std::endl;

    // Try to increment the grade of b1
    try {
        b1.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << b1 << std::endl;

    try {
        b1.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << b1 << std::endl;

    // Create a bureaucrat with a grade of 150
    Bureaucrat b2("Ehab", 150);
    std::cout << b2 << std::endl;

    // Try to decrement the grade of b2
    try {
        b2.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << b2 << std::endl;

    try {
        b2.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << b2 << std::endl;

    // Create a bureaucrat with a grade of 0
    try {
        Bureaucrat b3("John", 0);
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }

    // Create a bureaucrat with a grade of 151
    try {
        Bureaucrat b4("Doe", 151);
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }

    // Create a bureaucrat with a grade of 50
    Bureaucrat b5("Jane", 50);
    std::cout << b5 << std::endl;

    // Try to increment the grade of b5 50 times
    for (int i = 0; i < 55; i++) {
        try {
            b5.incrementGrade();
        } catch (std::exception& e) {
            std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << b5 << std::endl;

    // Try to increment the grade of b5 one more time
    try {
        b5.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << b5 << std::endl;

    // Create a bureaucrat with a grade of 100
    Bureaucrat b6("Bob", 100);
    std::cout << b6 << std::endl;

    // Try to decrement the grade of b6 100 times
    for (int i = 0; i < 55; i++) {
        try {
            b6.decrementGrade();
        } catch (std::exception& e) {
            std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
        }
    }
    std::cout << b6 << std::endl;

    // Try to decrement the grade of b6 one more time
    try {
        b6.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
    std::cout << b6 << std::endl;

    return 0;
}