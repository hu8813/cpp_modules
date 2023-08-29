#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
# include <iostream>
# include <string>

class Point
{
	public:
		// Constructors
		Point();
		Point(const Point &copy);
		Point(const Fixed x, const Fixed y);
		
		// Destructor
		~Point();
		
		// Operators
		const Point & operator=(const Point &assign);
		
		// Getters / Setters
		Fixed getX() const;
		Fixed getY() const;
		
	private:
		const Fixed _x;
		const Fixed _y;
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif