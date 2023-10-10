
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments\nUsage: ./convert <value>\n";
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}