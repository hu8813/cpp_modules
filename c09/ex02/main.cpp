#include "PmergeMe.hpp"

bool parseAndStoreNumbers(int argc, char *argv[], std::vector<int>& numVector)
{
    int i = 0;
    while (++i < argc)
    {
        int j = 0;
        if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
        {
            std::cout << "Error\n";
            return false;
        }

        while (argv[i][j] != '\0')
        {
            if ((!(isdigit(argv[i][j])) && (argv[i][j] != ' ')
                && (argv[i][j] != '+' && argv[i][j] != ' '))
                || (argv[i][j] == '-')
                || (argv[i][j] == '+' && argv[i][j + 1] == '\0')
                || (argv[i][j] == '+' && argv[i][j + 1] == ' '))
            {
                std::cout << "Error\n";
                return false;
            }
            j++;
        }

        int num;
        std::istringstream iss(argv[i]);

        try
        {
            if (!(iss >> num))
            {
                std::cout << "Error: Invalid number format." << std::endl;
                return false;
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            return false;
        }

        if (std::find(numVector.begin(), numVector.end(), num) != numVector.end())
        {
            std::cout << "Error: Duplicate number found." << std::endl;
            return false;
        }

        numVector.push_back(num);
    }
    return true;
}

int main(int argc, char *argv[])
{
    clock_t parsingStart = clock();
    if (argc < 3)
    {
        std::cout << "Error: At least 2 numbers are required as an argument." << std::endl;
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
        std::vector<int> vec;
        clock_t startSortVec = clock();
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

        std::cout << std::endl << "After: ";
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
