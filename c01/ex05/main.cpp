#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    if (argc == 2) {
        std::string msg(argv[1]);
        harl.complain(msg);
    }
    else
    {
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    }
    return 0;
}