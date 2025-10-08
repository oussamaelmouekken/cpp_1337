#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const  &other) 
{
    (void)other;
    std::cout << "ScalarConverter copied! (This should not happen!)" << std::endl;
}

ScalarConverter &ScalarConverter ::operator=(ScalarConverter const &other) 
{
    (void)other;
    std::cout << "ScalarConverter assigned! (This should not happen!)" << std::endl;
    return *this;
}

void ScalarConverter :: convert(const std::string &literal)
{
    bool a,b,c,d;
    a = convert_tochar(literal);
    b = convert_toint(literal);
    c = convert_tofloat(literal);
    d = convert_todouble(literal);
    if(!a || !b || !c ||!d)
     std::cout<<"not valid\n";
}
