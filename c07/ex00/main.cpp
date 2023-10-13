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

    std::cout << std::endl;
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


    std::cout << std::endl;

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
    
    
    std::cout << std::endl;

    char g = 'a';
    char h = 'b';

    std::cout << "g = " << g << ", h = " << h << std::endl;
    
    // swap

    swap(g, h);

    std::cout << "After swap(g, h):" << std::endl;

    std::cout << "g = " << g << ", h = " << h << std::endl;

    // min

    std::cout << "min(g, h) = " << min(g, h) << std::endl;

    // max

    std::cout << "max(g, h) = " << max(g, h) << std::endl;


    std::cout << std::endl;

    return 0;
}
