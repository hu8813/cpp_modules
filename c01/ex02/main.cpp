# include <iostream>
# include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* strPtr = &str;
    std::string& strRef = str;

    std::cout << "str   : " << &str << std::endl;
    std::cout << "strPtr: " << strPtr << std::endl;
    std::cout << "strRef: " << &strRef << std::endl;

    std::cout << "str   : " << str << std::endl;
    std::cout << "strPtr: " << *strPtr << std::endl;
    std::cout << "strRef: " << strRef << std::endl;
    
    return 0;
}