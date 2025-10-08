/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:04 by oussama           #+#    #+#             */
/*   Updated: 2025/04/19 17:42:06 by oussama          ###   ########.fr       */
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
// int constructor
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
int Fixed::toInt(void) const
{
	return (this->value >> fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (this->value) / 256.0f;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    // Use the toFloat() member function to get the float representation
    os << fixed.toFloat();
    // Return the output stream object to allow chaining (e.g., std::cout << a << b;)
    return os;
}