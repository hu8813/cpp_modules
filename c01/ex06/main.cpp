#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error: wrong number of arguments" << std::endl;
        std::cout << "Usage: " << argv[0] << " MSG" << std::endl;
        return 1;
    }
    Harl harl;
    std::string msg(argv[1]);
    //std::cout << "msg: " << msg << std::endl;
    harl.complain(msg);

    // harl.complain("DEBUG");
    // harl.complain("INFO");
    // harl.complain("WARNING");
    // harl.complain("ERROR");

    return 0;
}