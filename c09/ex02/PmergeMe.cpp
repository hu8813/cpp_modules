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

bool PmergeMe::parseAndStoreNumbers(int argc, char **argv, std::deque<int> &deq)
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

        if (std::find(deq.begin(), deq.end(), num) != deq.end())
        {
            std::cerr << "Error:\nDuplicate number found." << std::endl;
            return false;
        }

        deq.push_back(num);
    }
    if (deq.size() < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return false;
    }
    return true;
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;

    for (int it = 1; it < static_cast<int>(vec.size()); it += 2) {
        if (vec[it] < vec[it - 1]) {
            std::swap(vec[it], vec[it - 1]);
        }
    }

    std::vector<int> sorted;
    for (int i = 1; i < static_cast<int>(vec.size()); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }

    sorted.push_back(vec[0]);

    for (int i = 1; i < static_cast<int>(vec.size()); ++i) {
        int key = vec[i];

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

    for (int i = 0; i < static_cast<int>(vec.size()); ++i) {
        vec[i] = sorted[i];
    }
}

void PmergeMe::mergeInsertSort(std::deque<int>& deq) {
    if (deq.size() <= 1) return;

    for (int it = 1; it < static_cast<int>(deq.size()); it += 2) {
        if (deq[it] < deq[it - 1]) {
            std::swap(deq[it], deq[it - 1]);
        }
    }

    std::deque<int> sorted;
    for (int i = 1; i < static_cast<int>(deq.size()); ++i) {
        int key = deq[i];
        int j = i - 1;
        while (j >= 0 && deq[j] > key) {
            deq[j + 1] = deq[j];
            --j;
        }
        deq[j + 1] = key;
    }

    sorted.push_back(deq[0]);

    for (int i = 1; i < static_cast<int>(deq.size()); ++i) {
        int key = deq[i];

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

    for (int i = 0; i < static_cast<int>(deq.size()); ++i) {
        deq[i] = sorted[i];
    }
}



