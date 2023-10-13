#pragma once

#include "Array.hpp"

// Default constructor
template<typename T>
Array<T>::Array() : _size(0), _array(NULL) {}

// Constructor with size parameter
template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {}

// Copy constructor
template<typename T>
Array<T>::Array(const Array& other) : _size(other._size), _array(new T[other._size]) {
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

// Destructor
template<typename T>
Array<T>::~Array() {
    if (_size > 0 && _array)
    delete[] _array;
}

// Assignment operator
template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

// Operator[] overload
template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw OutOfBounds();
    }
    return _array[index];
}

// Const operator[] overload
template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw OutOfBounds();
    }
    return _array[index];
}

// Getter for size
template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}

// OutOfBoundsException class
template<typename T>
const char* Array<T>::OutOfBounds::what() const throw() {
    return "Index out of bounds";
}

// Operator<< overload
template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& array) {
	for (size_t i = 0; i < array.size(); i++) {
		std::cout << array[i] << " " ;
	}
    std::cout << std::endl;
	return (stream);
}
