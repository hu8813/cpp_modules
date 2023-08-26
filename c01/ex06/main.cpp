#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        std::cout << "Usage: " << argv[0] << " MSG" << std::endl;
        std::cout << "message can be DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    std::string msg(argv[1]);
    harl.complain(msg);
    
    // harl.complain("DEBUG");
    // harl.complain("INFO");
    // harl.complain("WARNING");
    // harl.complain("ERROR");

    return 0;
}