/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:27:34 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/24 15:01:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Ice::Ice() : type_("ice")
{
	std::cout << this->type_ << " has been created" << std::endl;
}

Ice::Ice(const Ice &base) : AMateria(), type_(base.type_)
{
	std::cout << this->type_ << " has been created from copy" << std::endl;
}

Ice &Ice::operator=(const Ice &base)
{
	if (this != &base)
	{
		this->type_ = base.getType();
		std::cout << "A new ice Materia was assigned" << std::endl;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << this->type_ << " has been destroyed" << std::endl;
	
}

std::string const &Ice::getType() const
{
	return (this->type_);
}

Ice *Ice::clone() const
{
	Ice	*dolly = new Ice;
	return (dolly);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	
}
