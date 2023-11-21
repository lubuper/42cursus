/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/17 17:40:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :type("Dog")
{
	std::cout << "Default Dog constructor" << std::endl;
}

Dog::Dog(const Dog &base) : Animal(), type(base.type)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog	&Dog::operator=(const Dog &base)
{
	std::cout << "Dog assignment operator" << std::endl;
	if (this != &base)
		this->type = base.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dogstructor" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->type);
}

void	Dog::makeSound(void) const
{
	std::cout << "\033[34m*BARK* *BARK*\033[0m" << std::endl;
}
