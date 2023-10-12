#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    delete [] mirror;//
    return 0;
}
{
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
}
}