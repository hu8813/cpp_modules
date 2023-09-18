#pragma once
#include <iostream>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
	
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		
		// Getters / Setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
	private:
		int _rawBits;
		static const int _bits = 8;
		
};
