#pragma once

#include <stack>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
public:
    RPN();
    ~RPN();

    RPN(const RPN &other);
    RPN &operator=(const RPN &);

    double evaluate(const std::string &expression);

private:
    bool isOperator(const char ch) const;
    double performOperation(const char op, double a, double b);

    std::stack<double> values;
};
