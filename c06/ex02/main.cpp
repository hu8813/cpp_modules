#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int i = rand() % 3;

    switch (i)
    {
    case 0:
        return new A();
        break;
    case 1:
        return new B();
        break;
    case 2:
        return new C();
        break;
    default:
        return new A();
        break;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Type of pointer is:\t A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type of pointer is:\t B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Type of pointer is:\t C" << std::endl;
    else
        std::cout << "Unknown pointer Type" << std::endl;
}

void identify(Base &p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "Type of reference is:\t A" << std::endl;
    } catch (std::exception &) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "Type of reference is:\t B" << std::endl;
        } catch (std::exception &) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "Type of reference is:\t C" << std::endl;
            } catch (std::exception &) {
                std::cout << "Unknown reference Type" << std::endl;
            }
        }
    }
}

int main()
{
    try {
        std::srand(std::time(NULL));
        for (int i=0; i<5; i++)
        {
            Base *base = generate();
            Base &ref = *base;
            try {
                identify(base);
                identify(*base);
                identify(&ref);
            } catch (std::exception& e) {
                std::cerr << "Exception caught: " << e.what() << std::endl;
            }
            delete base;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
