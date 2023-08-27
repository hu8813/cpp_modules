#include <iostream>
#include <fstream>
#include "Replace.hpp"

int main(int argc, char **argv)
{
 if (argc != 4) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename(argv[1]);
    std::string oldString(argv[2]);
    std::string newString(argv[3]);

    Replace fr(filename, oldString, newString);
    fr.run();

    return 0;
}
