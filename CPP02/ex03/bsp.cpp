/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:40:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 15:10:49 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	triangleArea(Point const a, Point const b, Point const c)
{
	Fixed	value;
	value =	(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	return (std::abs(value.toFloat()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcArea = triangleArea(a, b, c);
	if (abcArea <= 0)
	{
		std::cout << "This is not a valid triangle" << std::endl;
		return(false);
	}
	Fixed	aTriangle = triangleArea(point, b, c);
	Fixed	bTriangle = triangleArea(a, point, c);
	Fixed	cTriangle = triangleArea(a, b, point);
	Fixed	percentA = aTriangle / abcArea;
	Fixed	percentB = bTriangle / abcArea;
	Fixed	percentC = cTriangle / abcArea;
	
	if (percentA > 0 && percentA < 1 && percentB > 0 && percentB < 1 && percentC > 0 && percentB < 1)
	{
		std::cout << "This point is \033[33mINSIDE\033[0m the triangle" <<std::endl;	
		return(true);
	}
	else if (percentA == 0 || percentA == 1 || percentB == 0 || percentB == 1 || percentC == 0 || percentB == 1)
	{
		std::cout << "This point is \033[34mOUTSIDE\033[0m the triangle" <<std::endl;
		return(false);
	}
	return(false);
}