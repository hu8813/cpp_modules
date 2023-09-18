#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    std::string args;
    for (int i = 1; i < argc; ++i) {
        args += argv[i];
    }

    for(std::size_t j = 0; j < args.length(); j++){
        args.at(j) =  std::toupper(args.at(j));
    }

        /* // alternatives:
        for (std::string::size_type j = 0; j < arg.size(); ++j) {
             arg[j] = std::toupper((arg[j]));
        }

        for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
            *it = std::toupper((*it));
        }
        std::cout << arg;
        */
    
    std::cout << args;
    std::cout << std::endl;

    return 0;
}
