#pragma once

#include <iostream>

template<typename T>
void iter(T *arr, int len, void (*f)(T &)) {
    if (len < 0)
    {
        std::cerr << "\033[1;31mError:\033[0m len must be positive" << std::endl;
        return;
    }
    for (int i = 0; i < len; i++) {
        f(arr[i]);
    }
}

template<typename T>
void iter(const T *arr, int len, void (*f)(T const &)) {
    if (len < 0)
    {
        std::cerr << "\033[1;31mError:\033[0m len must be positive" << std::endl;
        return;
    }
    for (int i = 0; i < len; i++) {
        f(arr[i]);
    }
}

template<typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

template<typename T>
void print(T &x) {
    std::cout << x << std::endl;
}
