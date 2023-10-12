#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);

    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;

    unsigned int size() const;

private:
    unsigned int _size;
    T* _array;
};

#include "Array.tpp"
