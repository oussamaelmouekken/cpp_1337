#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <stdexcept>
#include <iostream>
#include <list>
#include <vector>

class Span
{
  private:
	unsigned int max_size;
	std::vector<int> numbers;

  public:
	// Orthodox Canonical Form
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	// Member functions
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
};

#endif
