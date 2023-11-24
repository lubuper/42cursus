/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 09:42:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : type("Dog")
{
	std::cout << "Default Dog constructor" << std::endl;
	this->brain_ = new Brain();
}

Dog::Dog(const Dog &base) : type(base.type)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->brain_ = new Brain(*base.brain_);
}

Dog	&Dog::operator=(const Dog &base)
{
	std::cout << "Dog assignment operator" << std::endl;
	if (this != &base)
	{
		this->type = base.type;
		this->brain_ = new Brain(*base.brain_);
	}
	return (*this);
}

Dog::~Dog()
{
	delete this->brain_;
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
