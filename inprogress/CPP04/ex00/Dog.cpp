/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:30 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :type("Dog")
{
	std::cout << "Default Dog constructor" << std::endl;
	return ;
}

Dog::Dog(const Dog &base) : type(base.type)
{
	std::cout << "Dog copy constructor" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog &base)
{
	if (this != &base)
		this->type = base.type;
	std::cout << "Dog assignment operator" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dogstructor" << std::endl;
	return ;
}

std::string	Dog::getType(void) const
{
	return (this->type);
}

void	Dog::makeSound(void) const
{
	std::cout << "*BARK* *BARK*" << std::endl;
}
