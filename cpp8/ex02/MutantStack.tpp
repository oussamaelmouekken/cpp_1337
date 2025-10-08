#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other)
{
    std::cout << "MutantStack copy constructor called" << std::endl;
}


template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    std::cout << "MutantStack assignment operator called" << std::endl;
    if (this != &other)
    {
        std::stack<T>::operator=(other);
    }
    return *this;
}


template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor called" << std::endl;
}

// Iterator functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    std::cout << "MutantStack begin() called" << std::endl;
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    std::cout << "MutantStack end() called" << std::endl;
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    std::cout << "MutantStack const begin() called" << std::endl;
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    std::cout << "MutantStack const end() called" << std::endl;
    return this->c.end();
}
