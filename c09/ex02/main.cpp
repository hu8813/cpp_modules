#include "PmergeMe.hpp"

bool parseAndStoreNumbers(int argc, char *argv[], std::vector<int>& vec, std::list<int>& lst)
{
    std::set<int> numSet;

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

        if (numSet.find(num) != numSet.end())
        {
            std::cout << "Error: Duplicate number found." << std::endl;
            return false;
        }

        numSet.insert(num);
        vec.push_back(num);
        lst.push_back(num);
    }
    return true;
}

int main(int argc, char *argv[])
{
    clock_t startProgram = clock();

    if (argc < 3)
    {
        std::cout << "Error: At least 2 numbers are required as an argument." << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::list<int> lst;

    if (!parseAndStoreNumbers(argc, argv, vec, lst))
    {
        return 1;
    }

    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    clock_t startSortVec = clock();
    mergeInsertSort(vec);
    clock_t endSortVec = clock();

    std::cout << std::endl << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    clock_t startSortLst = clock();
    mergeInsertSort(lst);
    clock_t endSortLst = clock();

    double timeSortVec = (double)(endSortVec - startProgram) / CLOCKS_PER_SEC;
    double timeSortLst = (double)(endSortLst - startSortLst + startSortVec - startProgram) / CLOCKS_PER_SEC;

    std::cout << "\nTime to process a range of " << vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << timeSortVec << " us" << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list : "
              << std::fixed << std::setprecision(5) << timeSortLst << " us" << std::endl;

    return 0;
}
