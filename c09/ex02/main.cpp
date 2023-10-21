#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error:\nAt least 2 numbers are required as an argument." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;

    // with a vector
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

    // with a deque
    clock_t startSortDeq = clock();

    std::deque<int> deq;
    if (!pmergeMe.parseAndStoreNumbers(argc, argv, deq))
    {
        return 1;
    }

    pmergeMe.mergeInsertSort(deq);
    std::cout << "After: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    clock_t endSortDeq = clock();

    double timeSortDeq = (double)(endSortDeq - startSortDeq) / CLOCKS_PER_SEC;

    double timeSortVec = (double)(endSortVec - startSortVec) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
            << std::fixed << std::setprecision(5) << timeSortVec << " us" << std::endl;
            
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: "
            << std::fixed << std::setprecision(5) << timeSortDeq << " us" << std::endl;

    return 0;
}
