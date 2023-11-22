/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:57:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 10:40:58 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Cure::Cure() : type_("cure")
{
	std::cout << this->type_ << " has been created" << std::endl;
}

Cure::Cure(const Cure &base) : AMateria(), type_(base.type_)
{
	std::cout << this->type_ << " has been created from copy" << std::endl;
	
}

Cure &Cure::operator=(const Cure &base)
{
	if (this != &base)
	{
		this->type_ = base.getType();
		std::cout << "A new cure Materia was assigned" << std::endl;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << this->type_ << " has been destroyed" << std::endl;
	
}

std::string const &Cure::getType() const
{
	return (this->type_);
}

Cure *Cure::clone() const
{
	Cure	*dolly = new Cure;
	return (dolly);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	
}
