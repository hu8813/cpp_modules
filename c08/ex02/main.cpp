#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "\033[1;33mTesting with MutantStack:\033[0m" << std::endl;

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        if (!mstack.empty())
        {
        std::cout << "Top element: " << mstack.top() << std::endl;
        mstack.pop();
        }

        std::cout << "Size: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << "\033[1;33mTesting with List:\033[0m" << std::endl;
        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        if (!mstack.empty())
        {
        std::cout << "Top element: " << mstack.back() << std::endl;
        mstack.pop_back();
        }

        std::cout << "Size: " << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << "\033[1;33mTesting with Vector:\033[0m" << std::endl;
        std::vector<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        if (!mstack.empty())
        {
        std::cout << "Top element: " << mstack.back() << std::endl;
        mstack.pop_back();
        }

        std::cout << "Size: " << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);

        std::vector<int>::iterator it = mstack.begin();
        std::vector<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
       {
        std::cout << "\033[1;33mTesting with Deque:\033[0m" << std::endl;
        std::deque<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        if (!mstack.empty())
        {
        std::cout << "Top element: " << mstack.back() << std::endl;
        mstack.pop_back();
        }

        std::cout << "Size: " << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);

        std::deque<int>::iterator it = mstack.begin();
        std::deque<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return (0);
}
