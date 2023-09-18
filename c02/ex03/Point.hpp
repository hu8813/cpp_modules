#pragma once

# include "Fixed.hpp"
# include <iostream>

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
		Point & operator=(const Point &);
		
		// Getters / Setters
		Fixed getX() const;
		Fixed getY() const;
		
	private:
		const Fixed _x;
		const Fixed _y;
		
};

void isPointInTriangle(Point a, Point b, Point c, Point point);
