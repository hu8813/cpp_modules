#pragma once

#include <iostream>
#include <exception>

class Form
{
private:
    std::string const _name;
    bool isSigned = false;
    int const gradeToSign;
    int const gradeToExecute;
public:
    Form();
    ~Form();
    void beSigned();
};

std::ostream& operator<<(std::ostream& os, const Form& form);
