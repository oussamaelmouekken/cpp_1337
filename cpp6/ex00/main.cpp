#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    if(ac != 2)
    {
        std::cout<<"error input ------ !!!!! \n";
        return 0;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
