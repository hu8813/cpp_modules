#pragma once

#include <vector>
#include <list>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cctype>
#include <set>
#include <algorithm>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &);

    void mergeInsertSort(std::vector<int> &vec);
    void mergeInsertSort(std::list<int> &lst);
    bool parseAndStoreNumbers(int argc, char **argv, std::vector<int> &vec);
    bool parseAndStoreNumbers(int argc, char **argv, std::list<int> &lst);

private:
};