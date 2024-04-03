/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 14:32:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	std::cout << "Example 1: inside" << std::endl;
	std::cout << "a = (0, 0)" << std::endl;
	std::cout << "b = (5, 5)" << std::endl;
	std::cout << "c = (0, 10)" << std::endl;
	std::cout << "Point = (1, 2)" << std::endl;
	{
		const Point	a(0.0f, 0.0f);
		const Point	b(5.0f, 5.0f);
		const Point	c(0.0f, 10.0f);
		const Point	point(1.0f, 2.0f);
		bsp(a, b, c, point);
		std::cout << std::endl;
	}
	std::cout << "Example 2: outside" << std::endl;
	std::cout << "a = (0, 0)" << std::endl;
	std::cout << "b = (5, 5)" << std::endl;
	std::cout << "c = (0, 10)" << std::endl;
	std::cout << "Point = (-1, -1)" << std::endl;
	{
		const Point	a(0, 0);
		const Point	b(5, 5);
		const Point	c(0, 10);
		const Point	point(-1, -1);
		bsp(a, b, c, point);
		std::cout << std::endl;
	}
	std::cout << "Example 3: on the side -> considered not inside" << std::endl;
	std::cout << "a = (0, 0)" << std::endl;
	std::cout << "b = (5, 5)" << std::endl;
	std::cout << "c = (0, 10)" << std::endl;
	std::cout << "Point = (0, 5)" << std::endl;
	{
		const Point	a(0, 0);
		const Point	b(5, 5);
		const Point	c(0, 10);
		const Point	point(0, 5);
		bsp(a, b, c, point);
		std::cout << std::endl;
	}
	std::cout << "Example 4: on triangle's vertex -> considered not inside" << std::endl;
	std::cout << "a = (0, 0)" << std::endl;
	std::cout << "b = (5, 5)" << std::endl;
	std::cout << "c = (0, 10)" << std::endl;
	std::cout << "Point = (5, 5)" << std::endl;
	{
		const Point	a(0, 0);
		const Point	b(5, 5);
		const Point	c(0, 10);
		const Point	point(5, 5);
		bsp(a, b, c, point);
		std::cout << std::endl;
	}
	std::cout << "Example 5: inside" << std::endl;
	std::cout << "a = (-2.2, -2.2)" << std::endl;
	std::cout << "b = (5.9, 5.9)" << std::endl;
	std::cout << "c = (-3.4, 10)" << std::endl;
	std::cout << "Point = (1, 2)" << std::endl;
	{
		const Point	a(-2.2f, -2.2f);
		const Point	b(5.9f, 5.9f);
		const Point	c(-3.4f, 10.0f);
		const Point	point(1.0f, 2.0f);
		bsp(a, b, c, point);
		std::cout << std::endl;
	}
	return (0);
}
