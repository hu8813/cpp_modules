#pragma once

#include <iostream>

template<typename T>
void iter(T *arr, size_t len, void (*f)(T &)) {
    for (size_t i = 0; i < len; i++) {
        f(arr[i]);
    }
}

template<typename T>
void iter(const T *arr, size_t len, void (*f)(T const &)) {
    for (size_t i = 0; i < len; i++) {
        f(arr[i]);
    }
}

template<typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

