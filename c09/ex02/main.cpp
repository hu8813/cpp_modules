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

    if (!pmergeMe.parseAndStoreNumbersInVec(argc, argv))
    {
        return 1;
    }

    std::cout << "Before: ";

    pmergeMe.printNumbersInVec();

    pmergeMe.mergeInsertSortVec();

    std::cout << std::endl;

    clock_t endSortVec = clock();

    // with a deque
    clock_t startSortDeq = clock();

    if (!pmergeMe.parseAndStoreNumbersInDeq(argc, argv))
    {
        return 1;
    }

    pmergeMe.mergeInsertSortDeq();
    std::cout << "After: ";
    pmergeMe.printNumbersInDeq();
    std::cout << std::endl;

    clock_t endSortDeq = clock();

    double timeSortDeq = (double)(endSortDeq - startSortDeq) / CLOCKS_PER_SEC;

    double timeSortVec = (double)(endSortVec - startSortVec) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << pmergeMe.getVecSize() << " elements with std::vector: "
            << std::fixed << std::setprecision(5) << timeSortVec << " us" << std::endl;
            
    std::cout << "Time to process a range of " << pmergeMe.getDeqSize() << " elements with std::deque: "
            << std::fixed << std::setprecision(5) << timeSortDeq << " us" << std::endl;

    return 0;
}
