/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:14 by oussama           #+#    #+#             */
/*   Updated: 2025/04/19 17:42:16 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();                         // Default constructor
    Fixed(const Fixed& src);         // Copy constructor
    ~Fixed();                        // Destructor
    Fixed& operator=(const Fixed& another); // Copy assignment operator

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif