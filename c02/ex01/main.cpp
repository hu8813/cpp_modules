#include <iostream>
#include "Fixed.hpp"

int main()
{
	{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
	Fixed const e(-10);
	Fixed const f(-42.52f);
	Fixed const g(1234.63222221f);
	Fixed const i(-42.42f);

	std::cout << "e is \t" << e << " \t\tas float, \t" << e.toInt() << " as integer" << std::endl;
	std::cout << "f is \t" << f << " \tas float, \t" << f.toInt() << " as integer" << std::endl;
	std::cout << "g is \t" << g << " \tas float, \t" << g.toInt() << " as integer" << std::endl;
	std::cout << "i is \t" << i << " \tas float, \t" << i.toInt() << " as integer" << std::endl;
	
	std::cout << "e is \t" << e.toInt() << " \t\tas int, \t" << e.toFloat() << " as float" << std::endl;
	std::cout << "f is \t" << f.toInt() << " \t\tas int, \t" << f.toFloat() << " as float" << std::endl;
	std::cout << "g is \t" << g.toInt() << " \t\tas int, \t" << g.toFloat() << " as float" << std::endl;
	std::cout << "i is \t" << i.toInt() << " \t\tas int, \t" << i.toFloat() << " as float" << std::endl;
	
	}
	return (0);
}