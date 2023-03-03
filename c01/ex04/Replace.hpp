#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>

class Replace {
public:
  Replace(const std::string& filename, const std::string& s1, const std::string& s2);
  void run();

private:
  std::string _filename;
  std::string _s1;
  std::string _s2;

  std::string replaceString(const std::string& str) const;
};

#endif 