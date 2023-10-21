#include "PmergeMe.hpp"

bool parseAndStoreNumbers(int argc, char **argv, std::vector<int> &numVector)
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

        if (std::find(numVector.begin(), numVector.end(), num) != numVector.end())
        {
            std::cerr << "Error:\nDuplicate number found." << std::endl;
            return false;
        }

        numVector.push_back(num);
    }
    if (numVector.size() < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    clock_t parsingStart = clock();
    if (argc < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return 1;
    }

    std::vector<int> numVector;

    if (!parseAndStoreNumbers(argc, argv, numVector))
    {
        return 1;
    }

    clock_t parsingTime = clock() - parsingStart;
    // Sorting and data management with a vector
    {
        clock_t startSortVec = clock();
        std::vector<int> vec;
        for (std::vector<int>::iterator it = numVector.begin(); it != numVector.end(); ++it)
        {
            vec.push_back(*it);
        }
        mergeInsertSort(vec);
        clock_t endSortVec = clock();

        std::cout << "Before: ";
        for (std::vector<int>::iterator it = numVector.begin(); it != numVector.end(); ++it)
        {
            std::cout << *it << " ";
        }

        std::cout << std::endl
                  << "After: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " ";
        }

        double timeSortVec = (double)(parsingTime + endSortVec - startSortVec) / CLOCKS_PER_SEC;

        std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector : "
                  << std::fixed << std::setprecision(5) << timeSortVec << " us" << std::endl;
    }

    // Sorting with a list
    {
        clock_t startSortLst = clock();
        std::list<int> lst;
        for (std::vector<int>::iterator it = numVector.begin(); it != numVector.end(); ++it)
        {
            lst.push_back(*it);
        }
        mergeInsertSort(lst);
        clock_t endSortLst = clock();

        double timeSortLst = (double)(parsingTime + endSortLst - startSortLst) / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << lst.size() << " elements with std::list : "
                  << std::fixed << std::setprecision(5) << timeSortLst << " us" << std::endl;
    }

    return 0;
}
