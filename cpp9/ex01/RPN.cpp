#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN()
{
    std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN &other) : stack(other.stack)
{
    std::cout << "Copy constructor called" << std::endl;
}

RPN &RPN::operator=(const RPN &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN()
{
    std::cout << "Destructor called" << std::endl;
}

void RPN::calculate(const std::string &expression)
{
    std::istringstream correct_data(expression);
    std::string data;
    while (correct_data >> data)
    {
        if (data == "+" || data == "-" || data == "*" || data == "/")
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands for operator '" + data + "'");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = 0;
            if (data == "+")
                result = a + b;
            else if (data == "-")
                result = a - b;
            else if (data == "*")
                result = a * b;
            else if (data == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero");
                result = a / b;
            }
            
            stack.push(result);
        }
        else
        {
            // validate integer input before using atoi
            bool valid = true;
            size_t i = 0;
            if (data[0] == '-') i = 1;
            if (data.empty() || (data == "-")) valid = false;
            for (; i < data.size(); i++)
            {
                if (!isdigit(data[i]))
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                throw std::runtime_error("Error: invalid data '" + data + "'");
            int num = atoi(data.c_str());
            if (num < -9 || num > 9)
                throw std::runtime_error("Error: out of range (-9 to 9): '" + data + "'");
            stack.push(num);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression");
    std::cout << "Result: " << stack.top() << std::endl;
}

