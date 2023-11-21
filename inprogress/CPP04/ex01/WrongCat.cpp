/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:41:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/17 17:08:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	std::cout << "Default WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &base) : type(base.type)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &base)
{
	if (this != &base)
		this->type = base.type;
	std::cout << "WrongCat assignment operator" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

std::string	WrongCat::getType(void) const
{
	return (this->type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "\033[31mATCHOO!\033[0m" << std::endl;
}