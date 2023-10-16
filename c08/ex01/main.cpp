#include <iostream>
#include "Span.hpp"

int main() {
    {
        Span span(5);

        // Test adding elements
        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(3);
        span.addNumber(4);
        span.addNumber(5);

        try {
            std::cout << "shortest span: "<< span.shortestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }

        try {
            std::cout << "longest span: "<< span.longestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }


        // Test adding more elements than the size of the container
        Span span2(2);
        span2.addNumber(1);
        span2.addNumber(2);
        try {
            span2.addNumber(3);
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }

        // Test getting the shortest span when there are no elements
        Span span3(0);
        try {
            std::cout << "shortest span: "<< span3.shortestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }

        // Test getting the longest span when there is only one element
        Span span4(1);
        span4.addNumber(1);
        try {
            std::cout << "longest span: "<< span4.longestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }
    }
    {
        Span span5(6);
        span5.addNumber(41);
        span5.addNumber(142);
        span5.addNumber(46);

        try {
            std::cout << "shortest span: "<< span5.shortestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }

        try {
            std::cout << "longest span: "<< span5.longestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }
    }
    {
        Span span6(15000);
        std::vector<int> v(15000);
        for (int i = 0; i < 15000; i++) {
            v[i] = i;
        }
        span6.addNumbers(v.begin(), v.end());

        try {
            std::cout << "shortest span: "<< span6.shortestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }

        try {
            std::cout << "longest span: "<< span6.longestSpan()<< std::endl;
        } catch (const std::exception& e) {
            std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
        }
    }
    return 0;
}
