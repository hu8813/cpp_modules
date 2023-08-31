#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

static void check_bsp_result(Point a, Point b, Point c, Point point)
{
    if ( bsp( a, b, c, point ) == true ) {
        std::cout << point.getX() << "." << point.getY() << ": Point is in the triangle" << std::endl;
    } else {
        std::cout << point.getX() << "." << point.getY() << ": Point is not in the triangle" << std::endl;
    }
}

int	main(void)
{
    Point a = Point(0, 0);
    Point b = Point(10, 30);
    Point c = Point(20, 0);
    Point point = Point(10, 2);
        
    check_bsp_result(a, b, c, point);



	return (0);
}
