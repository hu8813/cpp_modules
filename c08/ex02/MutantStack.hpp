#pragma once

#include <stack>
#include <deque>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
    typedef typename std::deque<T>::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};
