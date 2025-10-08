/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:41:58 by oussama           #+#    #+#             */
/*   Updated: 2025/04/19 17:42:02 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &old_objet)
{
	std::cout << "Copy constructor called\n";
	this->value = old_objet.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &right_old_objet)
{
	std::cout << "Copy assignment operator called\n";
	this->value = right_old_objet.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
	return (value);
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called\n";
    value = intValue << fractionalBits;
}

// Float constructor
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called\n";
    value = roundf(floatValue * (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (this->value) / 256.0f;
}

/// new for this 
///comparison operators 
bool Fixed::operator>(const Fixed& rhs) const {return this->value > rhs.getRawBits();}
bool Fixed::operator<(const Fixed& rhs) const {return this->value < rhs.getRawBits();}
bool Fixed::operator>=(const Fixed& rhs) const {return this->value >= rhs.getRawBits();}
bool Fixed::operator<=(const Fixed& rhs) const {return this->value <= rhs.getRawBits();}
bool Fixed::operator==(const Fixed& rhs) const {return this->value == rhs.getRawBits();}
bool Fixed::operator!=(const Fixed& rhs) const {return this->value != rhs.getRawBits();}

/// arithmetic operators

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->value + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->value - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    long long tmp = (this->value * rhs.getRawBits());
    tmp = tmp>>fractionalBits;
    Fixed result;
    result.setRawBits((int)tmp);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if(rhs.value == 0)
    {
        std::cout<<"Error: Division by zero\n";
        return Fixed();
    }
    long long tmp_numerator = (this->value) << fractionalBits;
    long long tmp_result = tmp_numerator / rhs.getRawBits();
    Fixed result;
    result.setRawBits((int)tmp_result);
    return result;
}

//// increment/decrement pre 
Fixed& Fixed::operator++()
{
    this->value++; 
    return *this;
}

Fixed& Fixed::operator--()
{
    this->value--; 
    return *this;
}
//// increment/decrement after 
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

/// function min and max 
Fixed& Fixed ::min(Fixed&a, Fixed&b)
{
    if(a < b)
        return a;
    else 
     return b;
}
const Fixed& Fixed ::min(const Fixed&a, const Fixed&b)
{
    if(a < b)
        return a;
    else
        return b;
    
}

Fixed& Fixed ::max(Fixed&a, Fixed&b)
{
    if(a > b)
        return a;
    else 
     return b;
}
const Fixed& Fixed ::max(const Fixed&a, const Fixed&b)
{
    if(a > b)
        return a;
    else
        return b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    // Use the toFloat() member function to get the float representation
    os << fixed.toFloat();
    // Return the output stream object to allow chaining (e.g., std::cout << a << b;)
    return os;
}
