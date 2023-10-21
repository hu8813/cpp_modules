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

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    return *this;
}

bool PmergeMe::parseAndStoreNumbers(int argc, char **argv, std::vector<int> &vec)
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

        if (std::find(vec.begin(), vec.end(), num) != vec.end())
        {
            std::cerr << "Error:\nDuplicate number found." << std::endl;
            return false;
        }

        vec.push_back(num);
    }
    if (vec.size() < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return false;
    }
    return true;
}

bool PmergeMe::parseAndStoreNumbers(int argc, char **argv, std::list<int> &lst)
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

        if (std::find(lst.begin(), lst.end(), num) != lst.end())
        {
            std::cerr << "Error:\nDuplicate number found." << std::endl;
            return false;
        }

        lst.push_back(num);
    }
    if (lst.size() < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec)
{
    if (vec.size() < 2)
        return;

    for (size_t i = 1; i < vec.size(); i += 2)
    {
        if (vec[i] < vec[i - 1])
        {
            std::swap(vec[i], vec[i - 1]);
        }
    }

    for (int i = 1; i < static_cast<int>(vec.size()); ++i)
    {
        int tmp = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > tmp)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = tmp;
    }
}

void PmergeMe::mergeInsertSort(std::list<int> &lst)
{
    if (lst.size() < 2)
        return;

    std::list<int>::iterator it = lst.begin();
    std::advance(it, 1);
    for (; it != lst.end(); ++it)
    {
        std::list<int>::iterator prev = it;
        --prev;
        if (*it < *prev)
        {
            std::swap(*it, *prev);
        }
    }

    it = lst.begin();
    std::advance(it, 1);
    for (; it != lst.end(); ++it)
    {
        int key = *it;
        std::list<int>::iterator j = it;
        --j;
        std::list<int>::iterator start = lst.begin();
        while (j != start && *j > key)
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = *j;
            --j;
        }
        if (j == start && *j > key)
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = *j;
            *j = key;
        }
        else
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = key;
        }
    }
}
