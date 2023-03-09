#include "Fixed.hpp"
#include "Point.hpp"

// Constructors
Point::Point()
{
	( Fixed ) this->_x = 0;
	( Fixed ) this->_y = 0;
	//std::cout << "\e[0;33mDefault Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const Point &copy)
{
	( Fixed ) this->_x = copy.getX();
	( Fixed ) this->_y = copy.getY();
	//std::cout << "\e[0;33mCopy Constructor called of Point\e[0m" << std::endl;
}

Point::Point(const float x, const float y)
{
	( Fixed ) this->_x = x;
	( Fixed ) this->_y = y;
	//std::cout << "\e[0;33mFields Constructor called of Point\e[0m" << std::endl;
}


// Destructor
Point::~Point()
{
	//std::cout << "\e[0;31mDestructor called of Point\e[0m" << std::endl;
}


// Operators
Point & Point::operator=(const Point &assign)
{
	if ( this != &assign ) {
	( Fixed ) this->_x = assign.getX();
	( Fixed ) this->_y = assign.getY();
	}
	return *this;
}

// Getters / Setters
Fixed Point::getX() const
{
	return this->_x;
}
Fixed Point::getY() const
{
	return this->_y;
}
