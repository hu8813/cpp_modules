#include "iter.hpp"

int main() {

    // Test 1: Test with array of integers
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "Testing with array of integers: "<< std::endl;
    ::iter(arr1, 5, &print);

    std::cout << std::endl;

    // Test 2: Test with array of strings
    std::string arr2[] = {"hello", "world", "!"};
    std::cout << "Testing with array of strings: "<< std::endl;
    ::iter(arr2, 3, &print);

    std::cout << std::endl;

    // Test 3: Test with empty array
    double arr3[] = {0};
    std::cout << "Testing with empty array: "<< std::endl;
    ::iter(arr3, 0, &print);

    std::cout << std::endl;

    // Test 5: Test with negative size
    char arr4[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::cout << "Testing with negative size: "<< std::endl;
    ::iter(arr4, -2, &print);

    std::cout << std::endl;

    // Test 6: Test with constant array
    const char arr5[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    std::cout << "Testing with constant array: "<< std::endl;
    ::iter(arr5, 3, &print);

    std::cout << std::endl;

    return 0;
}
