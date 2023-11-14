/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:13:37 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 18:47:49 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <istream>
# include <cmath>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fracBits = 8;
public:
	Fixed();
	Fixed(const Fixed &base);
	Fixed(const int intInput);
	Fixed(const float floatInput);
	~Fixed();
	Fixed &operator= (const Fixed &base);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed);

#endif