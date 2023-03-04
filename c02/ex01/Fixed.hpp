#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

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
		
		// Getters / Setters
		int getRawBits() const;
		void setRawBits(int const raw);
		int toInt() const;
		float toFloat( void ) const;
		
	private:
		int _rawBits;
		static const int _bits = 8;
		
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif