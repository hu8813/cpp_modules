#include "ScalarConverter.hpp"
#include <sstream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() : _str("") {}

ScalarConverter::ScalarConverter(const std::string &str) : _str(str) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _str(other._str) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
    {
        _str = other._str;
    }
    return *this;
}

void ScalarConverter::setInput(const std::string &str)
{
    _str = str;
}

std::string ScalarConverter::getInput() const
{
    return _str;
}

void ScalarConverter::convert(std::string _str)
{

    // Check if the input string is empty
    if (_str.empty())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    // check if its nan or nanf
    if (_str == "nan" || _str == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    // Try to convert to char
    try
    {
        std::istringstream iss(_str);
        int i;
        iss >> i;
        if (iss.fail() || i < 0 || i > 127)
        {
            std::cout << "char: impossible" << std::endl; // Conversion failed or outside the valid range
        }
        else
        {
            std::cout << "char: ";
            if (i < 32 || i > 126)
            {
                std::cout << "non-displayable" << std::endl; // Non-printable but valid
            }
            else
            {
                std::cout << static_cast<char>(i) << std::endl; // Printable
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "char: impossible" << std::endl; // Exception occurred
    }

    // Try to convert to int
    try
    {
        std::istringstream iss(_str);
        int i;
        iss >> i;
        if (iss.fail())
        {
            std::cout << "int: impossible" << std::endl; // Conversion failed
        }
        else
        {
            std::cout << "int: " << i << std::endl; // Successful conversion
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "int: impossible" << std::endl; // Exception occurred
    }

    // Try to convert to float
    try
    {
        std::istringstream iss(_str);
        float f;
        iss >> f;
        if (iss.fail())
        {
            std::cout << "float: impossible" << std::endl; // Conversion failed
        }
        else if (f == std::numeric_limits<float>::infinity())
        {
            std::cout << "float: " << _str << "f" << std::endl; // Positive infinity
        }
        else if (f == -std::numeric_limits<float>::infinity())
        {
            std::cout << "float: " << _str << "f" << std::endl; // Negative infinity
        }
        else if (std::isnan(f))
        {
            std::cout << "float: " << _str << "f" << std::endl; // NaN
        }
        else
        {
            std::cout << "float: " << f;
            if (f == static_cast<int>(f))
            {
                std::cout << ".0f" << std::endl; // Integer value
            }
            else
            {
                std::cout << "f" << std::endl; // Non-integer value
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "float: impossible" << std::endl; // Exception occurred
    }

    // Try to convert to double
    try
    {
        std::istringstream iss(_str);
        double d;
        iss >> d;
        if (iss.fail())
        {
            std::cout << "double: impossible" << std::endl; // Conversion failed
        }
        else if (d == std::numeric_limits<double>::infinity())
        {
            std::cout << "double: " << _str << std::endl; // Positive infinity
        }
        else if (d == -std::numeric_limits<double>::infinity())
        {
            std::cout << "double: " << _str << std::endl; // Negative infinity
        }
        else if (std::isnan(d))
        {
            std::cout << "double: " << _str << std::endl; // NaN
        }
        else
        {
            // Check if the input string is an integer (no decimal point)
            std::cout << "double: " << d;

            if (d == static_cast<int>(d))
            {
                std::cout << ".0"; // Integer value
            }

            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "double: impossible" << std::endl; // Exception occurred
    }
}
