#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cctype>
#include <deque>
#include <vector>
#include <algorithm>

class PmergeMe
{
public:
    PmergeMe();
    ~PmergeMe();
    
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &);

    bool parseAndStoreNumbers(int argc, char **argv, std::vector<int> &vec);
    bool parseAndStoreNumbers(int argc, char **argv, std::deque<int> &deq);
    void mergeInsertSort(std::vector<int> &vec);
    void mergeInsertSort(std::deque<int> &deq);

private:
};