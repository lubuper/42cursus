/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:20:30 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 18:58:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <istream>
# include <string>
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
	Fixed	&operator=(const Fixed &received);
	bool	operator<=(Fixed received) const;
	bool	operator<(Fixed received) const;
	bool	operator>=(Fixed received) const;
	bool	operator>(Fixed received) const;
	bool	operator==(Fixed received) const;
	bool	operator!=(Fixed received) const;
	float	operator+(Fixed received) const;
	float	operator-(Fixed received) const;
	float	operator*(Fixed received) const;
	float	operator/(Fixed received) const;
	Fixed	operator++(void);
	Fixed	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
	static Fixed	&min(Fixed &fixed1, Fixed &fixed2);
	static Fixed	&max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
	static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
};

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed);

#endif