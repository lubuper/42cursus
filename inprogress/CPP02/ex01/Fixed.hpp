/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:13:37 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/03 19:11:31 by lde-sous         ###   ########.fr       */
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
	;
public:
	Fixed(const int _intReceived);
	Fixed(const float _floatReceived);
	float	toFloat(void) const;
	int		toInt(void) const;
};

#endif