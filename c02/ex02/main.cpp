#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << " a + b = " << a + b << std::endl;
	std::cout << " a - b = " << a - b << std::endl;
	std::cout << " a * b = " << a * b << std::endl;
	std::cout << " a / b = " << a / b << std::endl;
	std::cout << "Minimum of a, b is = "<< Fixed::min(a, b) << std::endl;
	std::cout << "Maxumum of a, b is = "<< Fixed::max(a, b) << std::endl;

	return (0);
}
