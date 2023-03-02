#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4 || argv[1] == NULL || argv[2] == NULL || argv[3] == NULL
    || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cout << "Error: wrong Arguments" << std::endl;
        std::cout << "Usage: ./replace <file1> <string1> <string2>" << std::endl;
        return 1;
    }
    std::string file1 = argv[1];
    std::string string1 = argv[2];
    std::string string2 = argv[3];
    std::cout << "File1: " << file1 << std::endl;   
    std::cout << "String1: " << string1 << std::endl;
    std::cout << "String2: " << string2 << std::endl;
    
    std::ifstream infile(file1.c_str());
    std::string file2 = file1 + ".replace";
    std::ofstream outfile(file2.c_str());
    std::string line;
    while (std::getline(infile, line)) {
        std::string new_line;
        size_t pos = 0;
        while (pos < line.length()) {
            size_t found_pos = line.find(string1, pos);
            if (found_pos == std::string::npos) {
                new_line += line.substr(pos);
                break;
            } else {
                new_line += line.substr(pos, found_pos - pos);
                new_line += string2;
                pos = found_pos + string1.length();
            }
        }
        outfile << new_line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
