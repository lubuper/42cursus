/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:39 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 18:50:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;	
}

Fixed::Fixed(const Fixed &base)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = base.getRawBits();
	return ;
}

Fixed::Fixed(const int intInput)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intInput << this->_fracBits;
	return ;
}

Fixed::Fixed(const float floatInput)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(floatInput * (1 << this->_fracBits));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}


int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);	
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
	return ;
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fracBits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fracBits));
}

Fixed &Fixed::operator=(const Fixed &received)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &received)
		this->_fixedPointValue = received.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &COUT, Fixed const &fixed)
{
	COUT << fixed.toFloat();
	return (COUT);	
}

bool Fixed::operator<=(Fixed received) const
{
	return (this->toFloat() <= received.toFloat());
}

bool Fixed::operator<(Fixed received) const
{
	return (this->toFloat() < received.toFloat());
}

bool Fixed::operator>=(Fixed received) const
{
	return (this->toFloat() >= received.toFloat());
}

bool Fixed::operator>(Fixed received) const
{
	return (this->toFloat() > received.toFloat());
}

bool Fixed::operator==(Fixed received) const
{
	return (this->toFloat() == received.toFloat());
}

bool Fixed::operator!=(Fixed received) const
{
	return (this->toFloat() != received.toFloat());
}

float	Fixed::operator+(Fixed received)const
{
	return (this->toFloat() + received.toFloat());
}

float	Fixed::operator-(Fixed received)const
{
	return (this->toFloat() - received.toFloat());
}

float	Fixed::operator*(Fixed received)const
{
	return (this->toFloat() * received.toFloat());
}

float	Fixed::operator/(Fixed received)const
{
	return (this->toFloat() / received.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tempPrevious = *this;
	this->_fixedPointValue++;
	return (tempPrevious);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tempPrevious = *this;
	this->_fixedPointValue--;
	return (tempPrevious);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}
