#include "Replace.hpp"
#include <fstream>

Replace::Replace(const std::string& filename, const std::string& s1, const std::string& s2)
  : _filename(filename)
  , _s1(s1)
  , _s2(s2)
{
}

bool Replace::check_for_error()
{
  std::cout << "file: " << _filename << std::endl;
  std::cout << "s1: " << _s1 << std::endl;
  std::cout << "s2: " << _s2 << std::endl;
  return false;
}

void Replace::run() {

 if (check_for_error())
{
  std::ifstream infile(_filename.c_str());
  if (!infile.is_open()) {
    std::cerr << "Error: could not open file: " << _filename << std::endl;
    return;
  }

  std::string file2 = _filename + ".replace";
  std::ofstream outfile(file2.c_str());
  if (!outfile.is_open()) {
    std::cerr << "Error: could not create output file: " << file2 << std::endl;
    infile.close();
    return;
  }

  std::string line;
  while (std::getline(infile, line)) {
    outfile << replaceString(line) << std::endl;
  }

  infile.close();
  outfile.close();
}
}

std::string Replace::replaceString(const std::string& str) const {
  std::string newStr;
  size_t start = 0;
  size_t end;
  while ((end = str.find(_s1, start)) != std::string::npos) {
    newStr += str.substr(start, end - start);
    newStr += _s2;
    start = end + _s1.length();
  }
  newStr += str.substr(start);

  if (newStr.find(_s1) != std::string::npos) {
    newStr = replaceString(newStr);
  }

  return newStr;
}
