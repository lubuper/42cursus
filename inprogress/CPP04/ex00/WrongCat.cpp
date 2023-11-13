/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:41:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 19:48:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat")
{
	std::cout << "Default WrongCat constructor" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &base) : type(base.type)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	return ;
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
	return ;
}

std::string	WrongCat::getType(void) const
{
	return (this->type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "This cat is Wrong!" << std::endl;
}