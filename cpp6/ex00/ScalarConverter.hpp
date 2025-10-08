#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits.h>

class ScalarConverter 
{
    public:
        static void convert(const std::string &literal);

    private:
        ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter	&operator=(ScalarConverter const &other);
        ~ScalarConverter();

        static bool isChar(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isDouble(const std::string &literal);

        static bool convert_tochar(const std::string &literal);
        static bool convert_toint(const std::string &literal);
        static bool convert_tofloat(const std::string &literal);
        static bool convert_todouble(const std::string &literal);
};

#endif // SCALARCONVERTER_HPP