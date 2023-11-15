/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:27:34 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 18:41:59 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : _type("ice")
{
	std::cout << this->_type << " has been created" << std::endl;
	return ;
}

Ice::Ice(const Ice &base) : _type(base._type)
{
	std::cout << this->_type << " has been created from copy" << std::endl;
	return ;	
}

Ice &Ice::operator=(const Ice &base)
{
	if (this != &base)
	{
		this->_type = base.getType();
		std::cout << "A new ice Materia was assigned" << std::endl;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << this->_type << " has been destroyed" << std::endl;
	return ;
}

std::string const &Ice::getType() const
{
	return (this->_type);
}

Ice *Ice::clone() const
{
	Ice	*dolly = new Ice;
	return (dolly);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
