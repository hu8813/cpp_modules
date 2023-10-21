#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other) {
        std::stack<double> tmp;

        std::stack<double> otherCopy = other.values;
        while (!otherCopy.empty()) {
            tmp.push(otherCopy.top());
            otherCopy.pop();
        }

        while (!values.empty()) {
            values.pop();
        }

        while (!tmp.empty()) {
            values.push(tmp.top());
            tmp.pop();
        }
    }

    return *this;
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
            throw std::runtime_error("");
        }
        return a / b;
    default:
        throw;
    }
}

bool RPN::checkArgs(const std::string &args)
{
    int j = 0;

    while (args[j] != '\0')
    {
        if ((!isdigit(args[j]) && args[j] != ' ' && args[j] != '-' && args[j] != '+' && args[j] != '*' && args[j] != '/')
        || (args[j] == '-' && (args[j + 1] && (args[j + 1] != ' ' && args[j + 1] != '\0')))
        || (args[j] == '*' && (args[j + 1] && (args[j + 1] != ' ' && args[j + 1] != '\0')))
        || (args[j] == '/' && (args[j + 1] && (args[j + 1] != ' ' && args[j + 1] != '\0')))
        || (args[j] == '+' && (args[j + 1] && (args[j + 1] != ' ' && args[j + 1] != '\0'))))
        {
            return false;
        }
        j++;
    }
    return true;
}

double RPN::evaluate(const std::string &args)
{
    std::istringstream iss(args);
    std::string token;



    while (iss >> token)
    {
        if (isOperator(token[0]))
        {
            if (values.size() < 2)
            {
                throw std::runtime_error("");
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
                    throw std::runtime_error("");
                }
                values.push(value);
            }
            catch (const std::exception &e)
            {
                throw std::runtime_error("");
            }
        }
    }
    if (values.size() != 1)
    {
        throw std::runtime_error("");
    }
    return values.top();
}
