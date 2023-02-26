#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
    }
  
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    for (auto& c : arg) {
      c = std::toupper(c);
    }

    std::cout << arg;
    
    if (i < argc - 1) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;

  return 0;
}
