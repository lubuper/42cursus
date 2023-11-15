/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:57:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 18:39:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : _type("cure")
{
	std::cout << this->_type << " has been created" << std::endl;
}

Cure::Cure(const Cure &base) : _type(base._type)
{
	std::cout << this->_type << " has been created from copy" << std::endl;
	return ;
}

Cure &Cure::operator=(const Cure &base)
{
	if (this != &base)
	{
		this->_type = base.getType();
		std::cout << "A new cure Materia was assigned" << std::endl;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << this->_type << " has been destroyed" << std::endl;
	return ;
}

std::string const &Cure::getType() const
{
	return (this->_type);
}

Cure *Cure::clone() const
{
	Cure	*dolly = new Cure;
	return (dolly);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
