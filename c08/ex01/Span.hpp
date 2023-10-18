#pragma once

#include <set>
#include <iostream>
#include <vector>
#include <algorithm> // for "abs"

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    ~Span();

    Span& operator=(const Span& other);

    void addNumber(int num);
    void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

    int shortestSpan() const;
    int longestSpan() const;

private:
    std::multiset<int> _numbers;
    unsigned int _maxSize;
};
