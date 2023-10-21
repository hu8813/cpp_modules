#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " \"RPN_EXPRESSION\"" << std::endl;
        return 1;
    }

    RPN calculator;
    std::string expression = argv[1];

    try
    {
        double result = calculator.evaluate(expression);
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
