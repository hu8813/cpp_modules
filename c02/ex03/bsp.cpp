#include "Point.hpp"

static Fixed   abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static  Fixed area( Point const a, Point const b, Point const c )
{
    // std::cout << "a.x: "<< a.getX() << std::endl;
    // std::cout << "a.y: "<< a.getY() << std::endl;
    // std::cout << "b.x: "<< b.getX() << std::endl;
    // std::cout << "b.y: "<< b.getY() << std::endl;
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed   areaABC = ( Fixed ) abs(area(a, b, c));
    Fixed   areaPBC = ( Fixed ) abs(area(point, b, c));
    Fixed   areaAPC = ( Fixed ) abs(area(a, point, c));
    Fixed   areaABP = ( Fixed ) abs(area(a, b, point));
    if (areaABC == 0 || areaPBC == 0 || areaAPC == 0 || areaABP == 0)
    return (false);
    // std::cout << areaABC << std::endl;
    // std::cout << areaPBC << std::endl;
    // std::cout << areaAPC << std::endl;
    // std::cout << areaABP << std::endl;
    return ((areaABC == (areaPBC + areaAPC + areaABP)));
}

void isPointInTriangle(Point a, Point b, Point c, Point point)
{
    if ( bsp( a, b, c, point ) == true ) {
        std::cout << point.getX() << "." << point.getY() << ": Point is in the triangle" << std::endl;
    } else {
        std::cout << point.getX() << "." << point.getY() << ": Point is not in the triangle" << std::endl;
    }
}
