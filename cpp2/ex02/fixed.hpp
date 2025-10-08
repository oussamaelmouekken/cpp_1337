/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:41:55 by oussama           #+#    #+#             */
/*   Updated: 2025/04/19 18:09:51 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed {
private:
    int              value;
    static const int fractionalBits = 8;

public:
    // --- Orthodox Canonical Form ---
    Fixed();                          // Default Constructor
    Fixed(const Fixed& src);          // Copy Constructor
    ~Fixed();                         // Destructor
    Fixed& operator=(const Fixed& rhs); // Copy Assignment Operator

    float toFloat(void) const;
    // Additional constructors
	Fixed(const int intValue);     // Int constructor
	Fixed(const float floatValue); // Float constructor

    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    Fixed operator+(const Fixed& rhs)const;
    Fixed operator-(const Fixed& rhs)const;
    Fixed operator*(const Fixed& rhs)const;
    Fixed operator/(const Fixed& rhs)const;

    Fixed& operator++();// pre
    Fixed& operator--();// pre
    Fixed operator++(int);//after
    Fixed operator--(int);//after


    static Fixed& min(Fixed&a, Fixed&b);
    static const Fixed& min(const Fixed&a, const Fixed&b);
    static  Fixed& max(Fixed&a, Fixed&b);
    static const Fixed& max(const Fixed&a, const Fixed&b);

    int  getRawBits(void) const;
    void setRawBits(int const raw);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_HPP