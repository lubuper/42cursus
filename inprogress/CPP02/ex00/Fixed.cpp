/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:41:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 18:47:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &base)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = base.getRawBits();
	return ;
}

Fixed	&Fixed::operator= (const Fixed &base)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &base)
		this->_fixedPointValue = base.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);	
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
