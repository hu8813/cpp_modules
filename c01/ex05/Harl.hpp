#pragma once

#include <iostream>

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
