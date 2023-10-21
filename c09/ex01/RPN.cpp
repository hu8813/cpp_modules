#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

double RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token)
    {
        if (isOperator(token[0]))
        {
            if (values.size() < 2)
            {
                throw std::runtime_error("Invalid RPN expression");
            }
            double b = values.top();
            values.pop();
            double a = values.top();

            values.pop();
            values.push(performOperation(token[0], a, b));
        }
        else
        {
            double value;
            try
            {
                std::istringstream iss(token);
                iss >> value;
                if (value < 0 || value >= 10)
                {
                    throw std::runtime_error("Invalid RPN expression");
                }
                values.push(value);
            }
            catch (const std::exception &e)
            {
                throw;
            }
        }
    }
    if (values.size() != 1)
    {
        throw std::runtime_error("Invalid RPN expression");
    }
    return values.top();
}

bool RPN::isOperator(const char ch) const
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double RPN::performOperation(const char op, double a, double b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        return a / b;
    default:
        throw std::runtime_error("Unknown operator");
    }
}
