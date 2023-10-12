#pragma once

#include <iostream>

class Data
{
private:
    std::string _s1;
    int _n;
    std::string _s2;
public:
    Data(std::string s1 ="", int n=0, std::string s2 ="");
    Data(Data const &src);
    Data& operator=(Data const &src);
    std::string getS1() const;
    int getN() const;
    std::string getS2() const; 
    
    ~Data();
};



// struct Data {
//     std::string s1;
//     int         n;
//     std::string s2;
// };
