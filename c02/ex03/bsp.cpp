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

    return ((areaABC == (areaPBC + areaAPC + areaABP)));
}