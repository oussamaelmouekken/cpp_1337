#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), _size(0)
{
    std::cout << "Default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : data(NULL), _size(n)
{
    std::cout << "Parameterized constructor called\n";
    if (n > 0)
        data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T>& other) : data(NULL), _size(0)
{
    std::cout << "Copy constructor called\n";
    if (other._size > 0) {
        data = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; ++i)
            data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    std::cout << "Assignment operator called\n";
    if (this != &other) {
        delete[] data;
        data = NULL;
        _size = 0;
        if (other._size > 0) {
            data = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; ++i)
                data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Destructor called\n";
    delete[] data;
}

// function 
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index)const
{
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

