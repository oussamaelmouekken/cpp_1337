#ifndef WHATEVER_H
#define WHATEVER_H
#include <iostream>

template <typename T>

void iter(T*array, size_t lengh, void (*func)(T&))
{
    if (!array || !func) {
        std::cerr << "Error: null pointer provided\n";
        return;
    }
    for (size_t i = 0; i < lengh; i++)
    {
        func(array[i]);
    }
}

#endif