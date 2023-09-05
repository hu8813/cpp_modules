#include "Fixed.hpp"
#include "Point.hpp"

// Constructors
Point::Point() : _x((Fixed)0), _y((Fixed)0)
{
	std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
	//std::cout << "\e[0;33mCopy Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
	//std::cout << "\e[0;33mFields Constructor called of Point\e[0m" << std::endl;
}


// Destructor
Point::~Point()
{
	//std::cout << "\e[0;31mDestructor called of Point\e[0m" << std::endl;
}


// Operators
Point & Point::operator=(const Point &)
{
	return *this;
}

// Getters / Setters
Fixed Point::getX() const
{
	//std::cout << _x << std::endl;
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}
