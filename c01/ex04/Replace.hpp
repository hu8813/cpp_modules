#pragma once

#include <iostream>

class Replace {
public:
  Replace(const std::string& filename, const std::string& s1, const std::string& s2);
  bool check_for_error();
  void run();

private:
  std::string _filename;
  std::string _s1;
  std::string _s2;

  std::string replaceString(const std::string& str) const;
};
