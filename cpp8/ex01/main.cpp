#include "Span.hpp"

int	main(void)
{
	Span	sp(20);

	try
	{
		sp.addNumber(60);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(90);
		sp.addNumber(12);
        sp.addNumber(6);
		sp.addNumber(30);
		sp.addNumber(177);
		sp.addNumber(9);
		sp.addNumber(10);
        sp.addNumber(61);
		sp.addNumber(31);
		sp.addNumber(111);
		sp.addNumber(91);
		sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
	    std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
