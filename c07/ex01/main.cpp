#include "iter.hpp"
#include <iostream>
#include <string>

int main() {

    // Test 1: Test with array of integers
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "Testing with array of integers: "<< std::endl;
    ::iter(arr1, (unsigned int)5, &print);

    std::cout << std::endl;

    // Test 2: Test with array of strings
    std::string arr2[] = {"hello", "world", "!"};
    std::cout << "Testing with array of strings: "<< std::endl;
    ::iter(arr2, (unsigned int)3, &print);

    std::cout << std::endl;

    // Test 3: Test with empty array
    double arr3[] = {0};
    std::cout << "Testing with empty array: "<< std::endl;
    ::iter(arr3, (unsigned int)0, &print);

    std::cout << std::endl;

    return 0;
}