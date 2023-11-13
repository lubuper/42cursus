/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:02:36 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 13:07:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	return ;
}

Point::Point(float const x, float const y): x(x), y(y)
{
	return ;
}

Point::Point(Point	const &base) : x(base.x), y(base.y)
{
	return ;
}

Point	&Point::operator=(const Point &base)
{
	if (this != &base)
	{
		(Fixed)x = base.x;
		(Fixed)y = base.y;
	}
	return (*this);
}

Point::~Point()
{
	return ;
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

