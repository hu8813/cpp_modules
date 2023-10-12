#include "Array.hpp"
#include <iostream>

int main()
{
    // Create an array of integers with size 5
    Array<int> intArray(5);

    // Set values in the array
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i;
    }

    // Print the values in the array
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Create an array of strings with size 3
    Array<std::string> stringArray(3);

    // Set values in the array
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";

    // Print the values in the array
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;

    // Try to access an out-of-bounds index
    try
    {
        intArray[10] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
