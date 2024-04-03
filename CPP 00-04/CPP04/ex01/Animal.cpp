/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:24:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/17 17:06:31 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Default Animal constructor" << std::endl;
}

Animal::Animal(const Animal &base) : type(base.type)
{
	std::cout << "Animal copy constructor" << std::endl;
}

Animal	&Animal::operator=(const Animal &base)
{
	if (this != &base)
		this->type = base.type;
	std::cout << "Animal assignment operator" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal class destructor" << std::endl;
}

std::string	Animal::getType(void) const
{
	return(this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "\033[32mANIMAL SOUND!\033[0m" << std::endl;
}
