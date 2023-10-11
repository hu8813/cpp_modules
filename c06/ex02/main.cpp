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

    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
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

void identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "Type of reference is:\t A" << std::endl;
    else if (dynamic_cast<B *>(&p))
        std::cout << "Type of reference is:\t B" << std::endl;
    else if (dynamic_cast<C *>(&p))
        std::cout << "Type of reference is:\t C" << std::endl;
    else
        std::cout << "Unknown reference Type" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    for (int i=0; i<5; i++)
    {
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
    }

    return 0;
}
