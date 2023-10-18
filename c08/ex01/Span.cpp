#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other)  {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is already full");
    }
    _numbers.insert(number);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize) {
        throw std::out_of_range("Not enough space in Span to add all numbers");
    }
    _numbers.insert(begin, end);
}


int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::out_of_range("Span must contain at least 2 numbers");
    }
    std::multiset<int>::iterator it = _numbers.begin();
    int shortest = std::abs(*it - *(++it));
    if (it != _numbers.end()) {
    std::multiset<int>::iterator next = it;
    ++next;
    while (next != _numbers.end()) {
        int diff = std::abs(*next - *it);
        if (diff < shortest) {
            shortest = diff;
        }
        ++it;
        ++next;
    }
}

    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::out_of_range("Span must contain at least 2 numbers");
    }
    int min = *_numbers.begin();
    int max = *_numbers.rbegin();
    return max - min;
}
