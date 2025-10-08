#include "ScalarConverter.hpp"

bool ScalarConverter::convert_tochar(const std::string &literal)
{
    if(isChar(literal))
    {
        char c = literal[0];
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        return true;
    }
    else if (isInt(literal))
    {
        int value = std::atoi(literal.c_str());
        if (value < 0 || value > 255)
        {
        char truncated = static_cast<char>(value % 256);
        std::cout << "char: '" <<truncated<< "' (Truncated from " << value << ")" << std::endl;
        }
        else if (!isprint(static_cast<char>(value)))
            std::cout << "char: Non displayable" << std::endl;
        else if (value <= 126)
            std::cout << "char: '" <<static_cast<char>(value) << "'" << std::endl;
        else 
        std::cout << "char: '" <<static_cast<char>(value)<< "' (Extended ASCII)" << std::endl;
        return true;
    }
    else if (isFloat(literal))
    {
        float value = std::atof(literal.c_str());
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<char>(value)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    
        return true;
    }
    else if(isDouble(literal))
    {
        double value = std::strtod(literal.c_str(), NULL);
        if (literal == "nan" || literal == "+inf" || literal == "-inf")
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<char>(value)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        return true;
    }
    return false;
}

bool ScalarConverter::convert_toint(const std::string &literal)
{
    if (isChar(literal))
    {
        int c = static_cast<int>(literal[0]);
        std::cout<<"int: "<<c<<std::endl;
        return true;
    }
    else if (isInt(literal))
    {
        long value = std::atol(literal.c_str());
        if(value > INT_MAX || value < INT_MIN )
            std::cout<<"int : impossible \n";
        else 
         std::cout<<"int: "<<static_cast<int>(value) << std::endl;
        return true;
    }
    else if (isFloat(literal))
    {
        float value = std::atof(literal.c_str());
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
            std::cout << "int: impossible" << std::endl;
        else 
         std::cout<<"int: "<<static_cast<int>(value) << std::endl;
        return true;
    }
    else if (isDouble(literal))
    {
        double value = std::strtod(literal.c_str(), NULL);
        if (literal == "nan" || literal == "+inf" || literal == "-inf")
            std::cout << "int: impossible" << std::endl;
        else
            std::cout<<"int: "<<static_cast<int>(value) << std::endl;
        return true;
    }
    return false;
}


bool ScalarConverter::convert_tofloat(const std::string &literal)
{
    if (isChar(literal))
    {
        float  c = static_cast<float>(literal[0]);
        std::cout<<"float: "<<c<<".0f"<<std::endl;
        return true;
    }
    else if (isInt(literal))
    {
        long value = std::atol(literal.c_str());
        if(value > INT_MAX || value < INT_MIN )
            std::cout<<"float : impossible \n";
        else 
         std::cout<<"float: "<<static_cast<float>(value) << ".0f"<< std::endl;
        return true;
    }
    else if (isFloat(literal) || isDouble(literal))
    {
        long value = std::atol(literal.c_str());
        if(value > INT_MAX || value < INT_MIN )
            std::cout<<"float : impossible \n";
        else
        {
            if(isFloat(literal))
             std::cout<<"float: "<<literal <<std::endl;
            else
             std::cout<<"float: "<<literal <<"f"<<std::endl;
        }
        return true;
    }
    return false; 
}

bool ScalarConverter::convert_todouble(const std::string &literal)
{
    if (isChar(literal))
    {
        double  c = static_cast<double>(literal[0]);
        std::cout<<"double: "<<c<<".0"<<std::endl;
        return true;
    }
    else if (isInt(literal))
    {
        long value = std::atol(literal.c_str());
        if(value > INT_MAX || value < INT_MIN )
            std::cout<<"double : impossible \n";
        else 
         std::cout<<"double: "<<static_cast<double>(value) << ".0"<< std::endl;
        return true;
    }
    else if (isFloat(literal))
    {
        long value = std::atol(literal.c_str());
        if(value > INT_MAX || value < INT_MIN )
            std::cout<<"double : impossible \n";
        else
        {
            double v = std::atof(literal.c_str());
            std::cout<<"double: "<<static_cast<double>(v)<< std::endl;
        }
        return true;
    }
    else if(isDouble(literal))
    {
        long value = std::atol(literal.c_str());
        if(value > INT_MAX || value < INT_MIN )
            std::cout<<"double : impossible \n";
        else 
         std::cout<<"double: "<<literal <<std::endl;
        return true;
    }
    return false; 
}