/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:17 by oussama           #+#    #+#             */
/*   Updated: 2025/04/19 17:42:19 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed()
{
     value = 0;
     std::cout<<"Default constructor called\n";  
}
//copy assinement 
Fixed::~Fixed()
{
    std::cout<<"Destructor called\n";
}

Fixed :: Fixed(const Fixed& src)
{
    std::cout<<"Copy constructor called\n";
    this->value = src.getRawBits();
}
Fixed &Fixed ::operator=(const Fixed &another)
{
    std::cout<<"Copy assignment operator called\n";
    this->value = another.getRawBits();
    return *this ; 
}

void Fixed :: setRawBits(int const raw)
{
    value = raw;
}
int Fixed :: getRawBits(void) const
{
    std::cout<<"getRawBits member function called\n";
    return value;
}
