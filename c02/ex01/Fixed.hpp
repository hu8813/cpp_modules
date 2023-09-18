#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const int intNumber);
		Fixed(const float floatNumber);
		Fixed(const Fixed &copy);
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		
		// Getters / Setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
		
	private:
		int _rawBits;
		static const int _bits = 8;
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
