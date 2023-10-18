#pragma once

#include <iostream>
#include <algorithm> // for "find"
#include <vector>
#include <deque>
#include <list>
#include <set>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Value not found in container");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Value not found in container");
    return it;
}
