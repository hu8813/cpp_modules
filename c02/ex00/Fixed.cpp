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

Fixed::Fixed(int number)
{
	std::cout << "\e[0;33mFields Constructor called\e[0m" << std::endl;
	_rawBits = number;
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
int Fixed::getRawBits() const
{
	std::cout << "\e[0;32mgetRawBits member function called\e[0m" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}