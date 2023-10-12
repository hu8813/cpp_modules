#include "Data.hpp"

Data::Data(std::string s1, int n, std::string s2) : _s1(s1), _n(n), _s2(s2)
{
}

Data::Data(Data const &src)
{
    *this = src;
}

Data& Data::operator=(Data const &src)
{
    _s1 = src._s1;
    _n = src._n;
    _s2 = src._s2;
    return *this;
}

int Data::getN() const
{
    return _n;
}

std::string Data::getS1() const
{
    return _s1;
}

std::string Data::getS2() const
{
    return _s2;
}

Data::~Data()
{
    std::cout << "Data destroyed" << std::endl;
}