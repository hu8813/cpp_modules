#pragma once

#include <string.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);

    public:
       static void convert(std::string _str);

        class ConversionException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
