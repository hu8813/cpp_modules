#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;

    // Sorting and data management with a vector
    clock_t startSortVec = clock();

    std::vector<int> vec;
    if (!pmergeMe.parseAndStoreNumbers(argc, argv, vec))
    {
        return 1;
    }

    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }

    pmergeMe.mergeInsertSort(vec);

    std::cout << std::endl;

    clock_t endSortVec = clock();

    // Sorting with a list
    clock_t startSortLst = clock();

    std::list<int> lst;
    if (!pmergeMe.parseAndStoreNumbers(argc, argv, lst))
    {
        return 1;
    }

    pmergeMe.mergeInsertSort(lst);
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    clock_t endSortLst = clock();

    double timeSortVec = (double)(endSortVec - startSortVec) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << timeSortVec << " us" << std::endl;

    double timeSortLst = (double)(endSortLst - startSortLst) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list : "
              << std::fixed << std::setprecision(5) << timeSortLst << " us" << std::endl;

    return 0;
}
