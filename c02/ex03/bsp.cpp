#include "Point.hpp"

static Fixed   abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static  Fixed area( Point const a, Point const b, Point const c )
{
    return abs((a.getX() * (b.getY() - c.getY())) +
               (b.getX() * (c.getY() - a.getY())) +
               (c.getX() * (a.getY() - b.getY()))) / static_cast<Fixed>(2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    Fixed   areaABC = ( Fixed ) (area(a, b, c));
    Fixed   areaPBC = ( Fixed ) (area(point, b, c));
    Fixed   areaAPC = ( Fixed ) (area(a, point, c));
    Fixed   areaABP = ( Fixed ) (area(a, b, point));
    if (areaABC == 0 || areaPBC == 0 || areaAPC == 0 || areaABP == 0)
        return (false);
    std::cout << areaABC << ", " << areaPBC << ", " << areaAPC << ", " << areaABP << std::endl;
    return ((areaABC == (areaPBC + areaAPC + areaABP)));
}

void isPointInTriangle(Point a, Point b, Point c, Point point)
{
    std::cout << "(x,y) \t" << "a: " << a.getX() << "," << a.getY() << "\t b: " << b.getX() << "," << b.getY() << "\t c: "<< c.getX() << "," << c.getY()  << std::endl;
    if ( bsp( a, b, c, point ) == true ) {
        std::cout << "\e[0;34mPoint: "<< point.getX() << "," << point.getY() << " is in the triangle\e[0m" << std::endl;
    } else {
        std::cout << "\e[0;31mPoint: "<< point.getX() << "," << point.getY() << " is not in the triangle\e[0m" << std::endl;
    }
}
