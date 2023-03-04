#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}

Fixed::Fixed(int intNumber)
{
	std::cout << "\e[0;33mFields Constructor called\e[0m" << std::endl;
	_rawBits = intNumber << _bits;
}

Fixed::Fixed(float floatNumber)
{
	std::cout << "\e[0;33mFields Constructor called\e[0m" << std::endl;
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
int Fixed::getRawBits() const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)_rawBits / (1 << _bits);
}

int Fixed::toInt( void ) const
{
    if (_rawBits >= 0) {
        return _rawBits >> _bits;
    } else {
        int absRawBits = ~_rawBits + 1;
        return -(absRawBits >> _bits);
    }	
}

bool Fixed::operator>(const Fixed &rhs) const {
return _rawBits > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
return _rawBits < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
return _rawBits >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
return _rawBits <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
return _rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
return _rawBits != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
return Fixed(toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
return Fixed(toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
return Fixed(toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
return Fixed(toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
_rawBits++;
return *this;
}

Fixed Fixed::operator++(int) {
Fixed tmp(*this);
operator++();
return tmp;
}

Fixed &Fixed::operator--() {
_rawBits--;
return *this;
}

Fixed Fixed::operator--(int) {
Fixed tmp(*this);
operator--();
return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
return a > b ? a : b;
}