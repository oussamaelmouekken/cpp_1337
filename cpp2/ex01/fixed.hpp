/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:42:08 by oussama           #+#    #+#             */
/*   Updated: 2025/04/19 17:42:09 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int value;
	static const int fractionalBits = 8;

  public:
	// Orthodox Canonical Form
	Fixed();                                        // Default constructor
	Fixed(const Fixed &old_objet);                  // Copy constructor
	~Fixed();                                       // Destructor
	Fixed &operator=(const Fixed &right_old_objet); // Copy assignment operator
													// Renamed return type

	// Additional constructors
	Fixed(const int intValue);     // Int constructor
	Fixed(const float floatValue); // Float constructor

	// Conversion functions
	float toFloat(void) const;
	int toInt(void) const;

	// Raw bit iaccess
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

// Overload of the insertion («) operator declaration
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif // FIXED_HPP