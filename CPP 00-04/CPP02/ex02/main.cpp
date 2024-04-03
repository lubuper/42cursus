/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/14 14:32:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a = 1;
	Fixed const b( Fixed( 5.05f ) * Fixed(2));
	Fixed c = 0;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	std::cout << "a - 2 = " << (a - 2) << std::endl;
	std::cout << "a * 3 = " << (a * 3) << std::endl;
	std::cout << "a = " << (a = 3) << std::endl;
	std::cout << "10 / a = " << (Fixed(10) / a) << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "Fixed::max(a,b) < Fixed::min (a,b); True or false? : " << (Fixed::max(a, b) < Fixed::min(a, b)) << std::endl;
	std::cout << "Fixed::max(a,b) > Fixed::min (a,b); True or false? : " << (Fixed::max(a, b) > Fixed::min(a, b)) << std::endl;
	return (0);
}
