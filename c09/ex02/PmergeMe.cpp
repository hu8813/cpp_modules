#include "PmergeMe.hpp"

void mergeInsertSort(std::vector<int> &vec)
{
    if (vec.size() < 2)
        return;

    for (size_t i = 1; i < vec.size(); i += 2)
    {
        if (vec[i] < vec[i - 1])
        {
            std::swap(vec[i], vec[i - 1]);
        }
    }

    for (int i = 1; i < static_cast<int>(vec.size()); ++i)
    {
        int tmp = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > tmp)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = tmp;
    }
}

void mergeInsertSort(std::list<int> &lst)
{
    if (lst.size() < 2)
        return;

    std::list<int>::iterator it = lst.begin();
    std::advance(it, 1);
    for (; it != lst.end(); ++it)
    {
        std::list<int>::iterator prev = it;
        --prev;
        if (*it < *prev)
        {
            std::swap(*it, *prev);
        }
    }

    it = lst.begin();
    std::advance(it, 1);
    for (; it != lst.end(); ++it)
    {
        int key = *it;
        std::list<int>::iterator j = it;
        --j;
        std::list<int>::iterator start = lst.begin();
        while (j != start && *j > key)
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = *j;
            --j;
        }
        if (j == start && *j > key)
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = *j;
            *j = key;
        }
        else
        {
            std::list<int>::iterator nextJ = j;
            ++nextJ;
            *nextJ = key;
        }
    }
}
