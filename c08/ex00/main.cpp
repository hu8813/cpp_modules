
#include "easyfind.hpp"

int main()
{
    // Test with std::vector
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 73);
        std::cout << "Value found in vector at index " << std::distance(v.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    // Test with std::deque
    std::deque<int> d;
    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    d.push_back(9);
    d.push_back(10);

    try
    {
        std::deque<int>::iterator it = easyfind(d, 8);
        std::cout << "Value found in deque at index " << std::distance(d.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    // Test with std::list
    std::list<int> l;
    for (int i = 11; i <= 15; i++)
    {
        l.push_back(i);
    }

    try
    {
        std::list<int>::iterator it = easyfind(l, 13);
        std::cout << "Value found in list at index " << std::distance(l.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    return 0;
}
