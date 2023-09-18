#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

Fixed::Fixed(const int intNumber)
{
	std::cout << "\e[0;33mInt Constructor called\e[0m" << std::endl;
	_rawBits = intNumber << _bits;
}

Fixed::Fixed(const float floatNumber)
{
	std::cout << "\e[0;33mFloat Constructor called\e[0m" << std::endl;
	_rawBits = roundf(floatNumber * (1 << _bits));
}


Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	_rawBits = copy.getRawBits();
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}


// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "\e[0;34mCopy assignment operator called\e[0m" << std::endl;
	_rawBits = assign.getRawBits();
	return *this;
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// Getters / Setters
int Fixed::getRawBits(void) const
{
	std::cout << "\e[0;32mgetRawBits member function called\e[0m" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "\e[0;32msetRawBits member function called\e[0m" << std::endl;
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_rawBits) / (1 << _bits);
}

int Fixed::toInt(void) const {
    return static_cast<int>(roundf(toFloat()));
}