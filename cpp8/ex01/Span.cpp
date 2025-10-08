#include "Span.hpp"
#include <iostream>
#include <algorithm> // For std::sort

Span::Span() : max_size(0)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : max_size(N)
{
    std::cout << "Span parameterized constructor called" << std::endl;
}

// Copy constructor
Span::Span(const Span& other) : max_size(other.max_size), numbers(other.numbers)
{
    std::cout << "Span copy constructor called" << std::endl;
}

// Assignment operator
Span& Span::operator=(const Span& other)
{
    std::cout << "Span assignment operator called" << std::endl;
    if(this != &other)
    {
        this->max_size = other.max_size;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number)
{
    std::cout << "addNumber called" << std::endl;
    if(numbers.size() >= max_size)
    {
        throw std::runtime_error("this span is full");
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    std::cout << "shortestSpan called" << std::endl;
    if (numbers.size() < 2)
        throw std::runtime_error("Cannot find span with less than 2 numbers");
    
    // Create a copy of the vector and sort it
    std::vector<int> sorted_numbers = numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    unsigned int shortest = sorted_numbers[1] - sorted_numbers[0];
    for (size_t i = 2; i < sorted_numbers.size(); i++)
    {
        unsigned int diff = sorted_numbers[i] - sorted_numbers[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    std::cout << "longestSpan called" << std::endl;
    if (numbers.size() < 2)
        throw std::runtime_error("Cannot find span with less than 2 numbers");
    
    // Find min and max elements without sorting
    std::vector<int>::const_iterator min_it = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator max_it = std::max_element(numbers.begin(), numbers.end());
    
    return *max_it - *min_it;
}
