#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "Error: no input provided" << std::endl;
        return 1;
    }
    
    try
    {
        PmergeMe pmerge(av + 1);
        pmerge.sort();
        pmerge.printResults();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
