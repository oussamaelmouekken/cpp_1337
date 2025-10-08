#include "ScalarConverter.hpp"
// check input types 
bool ScalarConverter :: isChar(const std::string &literal)
{
    if (literal.length() == 1 && !isdigit(literal[0]))
		return true;
	return false;
}

bool ScalarConverter :: isInt(const std::string &literal)
{
    size_t i = 0;
    if(literal[0] == '+' || literal[0] == '-')
     i++;
    while(i < literal.length())
    {
        if(!isdigit(literal[i]))
         return 0;
        i++;
    }
    return 1;
}

bool ScalarConverter :: isFloat(const std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") 
    return true;
    if(literal[literal.size() - 1] != 'f' && literal[literal.size() - 1]!= 'F' ) 
        return false;
    std::string withoutsuffix = literal.substr(0, literal.length() - 1); // without f 
    bool hasDecimalPoint = (withoutsuffix.find('.') != std::string::npos);
    return hasDecimalPoint;// return true or false 
}

bool ScalarConverter :: isDouble(const std::string &literal)
{
    if (literal == "nan" || literal == "+inf" || literal == "-inf") 
     return true;
    bool hasDecimalPoint = (literal.find('.') != std::string::npos);
    return hasDecimalPoint;// return true or false 
}