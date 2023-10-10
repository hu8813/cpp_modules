#pragma once

#include <string.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

class ScalarConverter {
    private:
        std::string _str;
        ScalarConverter();
        ScalarConverter(const std::string& input);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

    public:
        void setInput(const std::string& str);
        std::string getInput() const;

        static void convert(std::string _str);

        class ConversionException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


