/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:49:38 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 09:42:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : type("Cat")
{
	std::cout << "Default Cat constructor" << std::endl;
	this->brain_ = new Brain();
}

Cat::Cat(const Cat &base) : type(base.type)
{
	std::cout << "Cat copy constructor" << std::endl;
	this->brain_ = new Brain(*base.brain_);
}

Cat	&Cat::operator=(const Cat &base)
{
	std::cout << "Cat assignment operator" << std::endl;
	if (this != &base)
	{
		this->type = base.type;
		this->brain_ = new Brain(*base.brain_);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain_;
	std::cout << "Cat destructor" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->type);
}

void	Cat::makeSound(void) const
{
	std::cout << "\033[33mMeowww\033[0m" << std::endl;
}