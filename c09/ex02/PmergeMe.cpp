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


void PmergeMe::mergeInsertSortVec() {
    if (_vec.size() <= 1) return;

    for (int it = 1; it < static_cast<int>(_vec.size()); it += 2) {
        if (_vec[it] < _vec[it - 1]) {
            std::swap(_vec[it], _vec[it - 1]);
        }
    }

    std::vector<int> sorted;
    for (int i = 1; i < static_cast<int>(_vec.size()); ++i) {
        int key = _vec[i];
        int j = i - 1;
        while (j >= 0 && _vec[j] > key) {
            _vec[j + 1] = _vec[j];
            --j;
        }
        _vec[j + 1] = key;
    }

    sorted.push_back(_vec[0]);

    for (int i = 1; i < static_cast<int>(_vec.size()); ++i) {
        int key = _vec[i];

        int left = 0;
        int right = static_cast<int>(sorted.size()) - 1;
        int insertIndex = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] < key) {
                insertIndex = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        sorted.insert(sorted.begin() + insertIndex, key);
    }

    for (int i = 0; i < static_cast<int>(_vec.size()); ++i) {
        _vec[i] = sorted[i];
    }
}

void PmergeMe::mergeInsertSortDeq() {
    if (_deq.size() <= 1) return;

    for (int it = 1; it < static_cast<int>(_deq.size()); it += 2) {
        if (_deq[it] < _deq[it - 1]) {
            std::swap(_deq[it], _deq[it - 1]);
        }
    }

    std::deque<int> sorted;
    for (int i = 1; i < static_cast<int>(_deq.size()); ++i) {
        int key = _deq[i];
        int j = i - 1;
        while (j >= 0 && _deq[j] > key) {
            _deq[j + 1] = _deq[j];
            --j;
        }
        _deq[j + 1] = key;
    }

    sorted.push_back(_deq[0]);

    for (int i = 1; i < static_cast<int>(_deq.size()); ++i) {
        int key = _deq[i];

        int left = 0;
        int right = static_cast<int>(sorted.size()) - 1;
        int insertIndex = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (sorted[mid] < key) {
                insertIndex = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        sorted.insert(sorted.begin() + insertIndex, key);
    }

    for (int i = 0; i < static_cast<int>(_deq.size()); ++i) {
        _deq[i] = sorted[i];
    }
}
