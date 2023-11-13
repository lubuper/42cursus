/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:38 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:45 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "Default Cat constructor" << std::endl;
	return ;
}

Cat::Cat(const Cat &base) : type(base.type)
{
	std::cout << "Cat copy constructor" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat &base)
{
	if (this != &base)
		this->type = base.type;
	std::cout << "Cat assignment operator" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	return ;
}

std::string	Cat::getType(void) const
{
	return (this->type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowww" << std::endl;
}