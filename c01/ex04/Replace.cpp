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
  if (_s1.empty() || _s1 == ""){
    std::cerr << "Error: The string to find can not be empty!"<< std::endl;
  return false;
  }
  if (_s1 == _s2){
    std::cerr << "Error: String to find and string to replace can not be same!"<< std::endl;
  return false;
  }
  if (_s2.empty() || _s2 == ""){
    std::cout << "Warning: The new string is empty. If any strings found they will be set to empty string."<< std::endl;
  }
  return true;
}

void Replace::run() {

 if (check_for_error())
{
  std::ifstream infile(_filename.c_str());
  if (!infile || infile.bad() || !infile.is_open()) {
    std::cerr << "Error: could not open file: " << _filename << std::endl;
    return ;
  }

  std::string file2 = _filename + ".replace";
  std::ofstream outfile(file2.c_str());
  if (!outfile || outfile.bad() || !outfile.is_open()) {
    std::cerr << "Error: could not create output file: " << file2 << std::endl;
    if (infile)
      infile.close();
    return ;
  }

  std::string line;
  std::string all_lines;
  while (std::getline(infile, line)) {
    all_lines += line;
    if (!infile.eof()) {
        all_lines += '\n';
    }
  
  }
  if (all_lines.find(_s1,0) == std::string::npos)
  {
    std::cout << "Warning: String to replace could not be found!" << std::endl;
    // outfile << all_lines;

    if (infile)
      infile.close();
    if (outfile)
      outfile.close();
    return ;
  }

  outfile << replaceString(all_lines);

  if (infile)
    infile.close();
  if (outfile)
  outfile.close();
}
}

std::string Replace::replaceString(const std::string& str) const {
    std::string newStr;
    static size_t start = 0;
    size_t end;
    
    while ((end = str.find(_s1, start)) != std::string::npos) {
        newStr += str.substr(start, end - start);
        newStr += _s2;
        start = end + _s1.length();
    }
    
    newStr += str.substr(start);

    // if (newStr.find(_s1, start) != std::string::npos) {
    //     newStr += replaceString(newStr);
    // }

    return newStr;
}

