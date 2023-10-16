#include "easyfind.hpp"

int main()
{
    std::cout << "\033[1;33mTesting with vector\033[0m" << std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 73);
        std::cout << "Value "<< *it << " found in vector at index " << std::distance(v.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    std::cout << "\033[1;33mTesting with deque\033[0m" << std::endl;

    std::deque<int> d;
    d.push_back(6);
    d.push_back(7);
    d.push_back(8);
    d.push_back(9);
    d.push_back(10);

    try
    {
        std::deque<int>::iterator it = easyfind(d, 8);
        std::cout << "Value "<< *it << " found in deque at index " << std::distance(d.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    std::cout << "\033[1;33mTesting with list\033[0m" << std::endl;

    std::list<int> l;
    for (int i = 11; i <= 15; i++)
    {
        l.push_back(i);
    }

    try
    {
        std::list<int>::iterator it = easyfind(l, 13);
        std::cout << "Value "<< *it << " found in list at index " << std::distance(l.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    std::cout << "\033[1;33mTesting with multiset\033[0m" << std::endl;

    std::multiset<int> m;
    for (int i = 11; i <= 15; i++)
    {
        m.insert(i);
    }

    try
    {
        std::multiset<int>::iterator it = easyfind(m, 13);
        std::cout << "Value "<< *it << " found in multiset at index " << std::distance(m.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }



    std::cout << "\033[1;33mTesting with set\033[0m" << std::endl;

    std::set<int> n;
    for (int i = 11; i <= 15; i++)
    {
        n.insert(i);
    }

    try
    {
        std::set<int>::iterator it = easyfind(n, 13);
        std::cout << "Value "<< *it << " found in set at index " << std::distance(n.begin(), it) << "!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "\033[1;31mError:\033[0m " << e.what() << std::endl;
    }

    return 0;
}
