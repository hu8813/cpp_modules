#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
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