/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:41:36 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/17 17:10:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default type from WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &base) : type(base.type)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &base)
{
	if (this != &base)
		this->type = base.type;
	std::cout << "WrongAnimal assignment operator" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal class destructor" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return(this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "\033[31mWrong Animal Sound\033[0m" << std::endl;
}