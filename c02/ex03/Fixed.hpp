#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(int intNumber);
		Fixed(float floatNumber);
		Fixed(const Fixed &copy);
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;
		Fixed & operator++();
		Fixed operator++(int);
		Fixed & operator--(); 
		Fixed operator--(int); 
		
		// Getters / Setters
		int getRawBits() const;
		void setRawBits(int const raw);
		int toInt() const;
		float toFloat( void ) const;

		static Fixed & min(Fixed &a, Fixed &b);
		static const Fixed & min(const Fixed &a, const Fixed &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static const Fixed & max(const Fixed &a, const Fixed &b);
		
		
	private:
		int _rawBits;
		static const int _bits = 8;
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
