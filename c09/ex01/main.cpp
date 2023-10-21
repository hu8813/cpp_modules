#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " \"RPN_EXPRESSION\"" << std::endl;
        return 1;
    }

    RPN calculator;
    std::string args = argv[1];

    if (!calculator.checkArgs(args))
        std::cerr << "Error" << std::endl;
    else
    {
        try
        {
            double result = calculator.evaluate(args);
            std::cout << result << std::endl;
        }
        catch (const std::exception &)
        {
            std::cerr << "Error" << std::endl;
        }
    }
    return 0;
}
