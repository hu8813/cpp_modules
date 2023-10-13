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
    class OutOfBounds : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    unsigned int size() const;

private:
    unsigned int _size;
    T* _array;
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& array);

#include "Array.tpp"
