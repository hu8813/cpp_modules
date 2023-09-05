#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int	main(void)
{
    Point a = Point(0, 0);
    Point b = Point(10, 30);
    Point c = Point(20, 0);
    //Point point = Point(10, 2);
    Point point = Point(10, 10);
        
    isPointInTriangle(a, b, c, point);


	return (0);
}
