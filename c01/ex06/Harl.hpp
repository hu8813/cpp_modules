#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl {
public:
	void complain(std::string level);
	Harl();
	~Harl();

private:
  	void debug();
    void info();
    void warning();
    void error();

};
#endif 
