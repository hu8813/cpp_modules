# include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPtr = &str;
    std::string &strRef = str;

    std::cout << "str Address    : " << &str << std::endl;
    std::cout << "strPtr Address : " << strPtr << std::endl;
    std::cout << "strRef Address : " << &strRef << std::endl;

    std::cout << "str Value      : " << str << std::endl;
    std::cout << "strPtr Value   : " << *strPtr << std::endl;
    std::cout << "strRef Value   : " << strRef << std::endl;
    
    strPtr = NULL; // strPtr is now a NULL pointer
    std::cout << "strPtr         : " << strPtr << std::endl;
    
    // strRef can not be set to NULL because it is a reference
    // &strRef = NULL;
    
    return 0;
}