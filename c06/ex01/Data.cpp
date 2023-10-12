#include "Data.hpp"
#include <iostream>

void Data::setStr(std::string str) {
    this->_str = str;
}

void Data::setInt(int num) {
    this->_num = num;
}

std::string Data::getStr() const {
    return this->_str;
}

int Data::getInt() const {
    return this->_num;
}

void Data::displayData() const {
    std::cout << "String: " << this->_str << std::endl;
    std::cout << "Integer: " << this->_num << std::endl;
}
