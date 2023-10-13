#pragma once
#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T& min(T& a, T& b) {
    return (a < b) ? a : b;
}

template<typename T>
T& max(T& a, T& b) {
    return (a > b) ? a : b;
}

// const versions

template<typename T>
void swap(const T& , const T& ) {
    std::cerr << "\033[1;31mError:\033[0m swap() cannot be called with const arguments" << std::endl;
}

template<typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}
