#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout<<"error input"<<std::endl;
        return 0;
    }
    RPN rpn;
    try
    {
        rpn.calculate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
