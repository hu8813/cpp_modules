#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int	main(void)
{
    {
    Point a = Point(-1, -1);
    Point b = Point(-5, -5);
    Point c = Point(-6, -1);
    Point point1 = Point(-4, -2);
    isPointInTriangle(a, b, c, point1);

    Point point2 = Point(10, 10);      
    isPointInTriangle(a, b, c, point2);

    Point point3 = Point(0, 0);      
    isPointInTriangle(a, b, c, point3);

    Point point4 = Point(-3, 3);      
    isPointInTriangle(a, b, c, point4);

    Point point5 = Point(-3, -3);      
    isPointInTriangle(a, b, c, point5);
    }
    std::cout << std::endl;
    {
    Point a = Point(1, 1);
    Point b = Point(5, 5);
    Point c = Point(6, 1);
    Point point1 = Point(4, 2);
    isPointInTriangle(a, b, c, point1);

    Point point2 = Point(10, 10);      
    isPointInTriangle(a, b, c, point2);

    Point point3 = Point(0, 0);      
    isPointInTriangle(a, b, c, point3);

    Point point4 = Point(-3, 3);      
    isPointInTriangle(a, b, c, point4);

    Point point5 = Point(-3, -3);      
    isPointInTriangle(a, b, c, point5);
    }
	return (0);
}
