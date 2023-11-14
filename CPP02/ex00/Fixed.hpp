/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:41:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 18:47:43 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <istream>
# include <locale>

class	Fixed
{
private:
	int	_fixedPointValue;
	static const int	_fracBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &base);
	Fixed &operator=(const Fixed &base);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif