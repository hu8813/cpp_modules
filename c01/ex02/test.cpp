#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;
int main()
{
	string	str;
	string* stringPTR = &str;
	string &stringREF = str;

	str = "HI THIS IS BRAIN";
	cout << "String Memory Address : " << &str << endl;
	cout << "Pointer Memory Address : " << stringPTR << endl;
	cout << "Reference Memory Address :" << &stringREF << endl;

	cout << "String Value : " << str << endl;
	cout << "Pointer Value : " << *stringPTR << endl;
	cout << "Reference Value : " << stringREF << endl;
}
