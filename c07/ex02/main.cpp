#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
{
    Array<int> numb;
    try
    {
        numb[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }
    
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
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    delete [] mirror;//
}
{
        Array<int> intArray(5);

    // Set values in the array
    for (unsigned int i = 0; i < 5; i++)
    {
        intArray[i] = i;
    }

    // Print the values in the array
    
    std::cout << intArray << std::endl;

    // Create an array of strings with size 3
    Array<std::string> stringArray(3);

    // Set values in the array
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";

    // Print the values in the array
    try
    {
        for (unsigned int i = 0; i < 4; i++)
        {
            std::cout << stringArray[i] << " ";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }
    
    
    std::cout << std::endl;

    // Try to access an out-of-bounds index
    try
    {
        intArray[10] = 42;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }
}
}