#include "whatever.hpp"
#include <iostream>

int main()
{
    int a = 42;
    int b = 24;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    // swap
    swap(a, b);
    std::cout << "After swap(a, b):" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // min
    std::cout << "min(a, b) = " << min(a, b) << std::endl;

    // max
    std::cout << "max(a, b) = " << max(a, b) << std::endl;


    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "c = " << c << ", d = " << d << std::endl;

    // swap
    swap(c, d);

    std::cout << "After swap(c, d):" << std::endl;

    std::cout << "c = " << c << ", d = " << d << std::endl;
    
    // min
    std::cout << "min(c, d) = " << min(c, d) << std::endl;

    // max

    std::cout << "max(c, d) = " << max(c, d) << std::endl;

    // add more tests with other variable types

    float e = 42.42f;
    float f = 24.24f;

    std::cout << "e = " << e << ", f = " << f << std::endl;

    // swap

    swap(e, f);

    std::cout << "After swap(e, f):" << std::endl;

    std::cout << "e = " << e << ", f = " << f << std::endl;

    // min

    std::cout << "min(e, f) = " << min(e, f) << std::endl;

    // max

    std::cout << "max(e, f) = " << max(e, f) << std::endl;
    
    

    return 0;
}
