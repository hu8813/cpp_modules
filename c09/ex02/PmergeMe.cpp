#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}



PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{
    return *this;
}

void PmergeMe::printNumbersInVec()
{
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

void PmergeMe::printNumbersInDeq()
{
    for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

int PmergeMe::getVecSize()
{
    return _vec.size();
}

int PmergeMe::getDeqSize()
{
    return _deq.size();
}

bool PmergeMe::parseAndStoreNumbersInVec(int argc, char **argv)
{
    std::string args;
    for (int i = 1; i < argc; i++)
    {
        if (i == 1)
            args = argv[1];
        else
            args = args + " " + argv[i];
    }
    int j = 0;

    while (args[j] != '\0')
    {
        if ((!(isdigit(args[j])) && (args[j] != ' ') && (args[j] != '+' && args[j] != ' ')) || (args[j] == '-') || (args[j] == '+' && args[j + 1] == '\0') || (args[j] == '+' && args[j + 1] == ' '))
        {
            std::cerr << "Error\n";
            return false;
        }
        j++;
    }

    int num;
    std::istringstream iss(args);
    while (!iss.eof() && iss.good())
    {
        try
        {
            if (!(iss >> num))
            {
                std::cerr << "Error: Invalid number format." << std::endl;
                return false;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error:\n"
                      << e.what() << std::endl;
            return false;
        }

        if (std::find(_vec.begin(), _vec.end(), num) != _vec.end())
        {
            std::cerr << "Error:\nDuplicate number found." << std::endl;
            return false;
        }

        _vec.push_back(num);
    }
    if (_vec.size() < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return false;
    }
    return true;
}

bool PmergeMe::parseAndStoreNumbersInDeq(int argc, char **argv)
{
    std::string args;
    for (int i = 1; i < argc; i++)
    {
        if (i == 1)
            args = argv[1];
        else
            args = args + " " + argv[i];
    }
    int j = 0;

    while (args[j] != '\0')
    {
        if ((!(isdigit(args[j])) && (args[j] != ' ') && (args[j] != '+' && args[j] != ' ')) || (args[j] == '-') || (args[j] == '+' && args[j + 1] == '\0') || (args[j] == '+' && args[j + 1] == ' '))
        {
            std::cerr << "Error\n";
            return false;
        }
        j++;
    }

    int num;
    std::istringstream iss(args);
    while (!iss.eof() && iss.good())
    {
        try
        {
            if (!(iss >> num))
            {
                std::cerr << "Error: Invalid number format." << std::endl;
                return false;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error:\n"
                      << e.what() << std::endl;
            return false;
        }

        if (std::find(_deq.begin(), _deq.end(), num) != _deq.end())
        {
            std::cerr << "Error:\nDuplicate number found." << std::endl;
            return false;
        }

        _deq.push_back(num);
    }
    if (_deq.size() < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::mergeInsertSortVec()
{
    if (_vec.size() <= 1) return;

    for (int i = 0; i < static_cast<int>(_vec.size()); i++)
    {
        if (i % 2 == 1 && _vec[i] < _vec[i - 1])
        {
            std::swap(_vec[i], _vec[i - 1]);
        }
    }

    std::vector<int> vecFirstElements;
    std::vector<int> vecSecondElements;

    for (int i = 0; i < static_cast<int>(_vec.size()); i++)
    {
        if (i % 2 == 0)
        {
            vecFirstElements.push_back(_vec[i]);
        }
        else
        {
            vecSecondElements.push_back(_vec[i]);
        }
    }

    for (int i = 1; i < static_cast<int>(vecFirstElements.size()); ++i)
    {
        int key = vecFirstElements[i];
        int j = i - 1;
        while (j >= 0 && vecFirstElements[j] > key)
        {
            vecFirstElements[j + 1] = vecFirstElements[j];
            --j;
        }
        vecFirstElements[j + 1] = key;
    }

    for (int i = 0; i < static_cast<int>(vecSecondElements.size()); i++)
    {
        const int key = vecSecondElements[i];

        std::vector<int>::iterator insertPos = std::lower_bound(vecFirstElements.begin(), vecFirstElements.end(), key);

        vecFirstElements.insert(insertPos, key);
    }
    
    for (int i= 0; i < static_cast<int>(vecFirstElements.size()); i++)
    {
        _vec[i] = vecFirstElements[i];
    }
}

void PmergeMe::mergeInsertSortDeq()
{
    if (_deq.size() <= 1)
        return;

    for (int i = 0; i < static_cast<int>(_deq.size()); i++)
    {
        if (i % 2 == 1 && _deq[i] < _deq[i - 1])
        {
            std::swap(_deq[i], _deq[i - 1]);
        }
    }

    std::deque<int> deqFirstElements;
    std::deque<int> deqSecondElements;

    for (int i = 0; i < static_cast<int>(_deq.size()); i++)
    {
        if (i % 2 == 0)
        {
            deqFirstElements.push_back(_deq[i]);
        }
        else
        {
            deqSecondElements.push_back(_deq[i]);
        }
    }

    for (int i = 1; i < static_cast<int>(deqFirstElements.size()); ++i)
    {
        int key = deqFirstElements[i];
        int j = i - 1;
        while (j >= 0 && deqFirstElements[j] > key)
        {
            deqFirstElements[j + 1] = deqFirstElements[j];
            --j;
        }
        deqFirstElements[j + 1] = key;
    }

    for (int i = 0; i < static_cast<int>(deqSecondElements.size()); i++)
    {
        const int key = deqSecondElements[i];

        std::deque<int>::iterator insertPos = std::lower_bound(deqFirstElements.begin(), deqFirstElements.end(), key);

        deqFirstElements.insert(insertPos, key);
    }

    for (int i= 0; i < static_cast<int>(deqFirstElements.size()); i++)
    {
        _deq[i] = deqFirstElements[i];
    }

}
