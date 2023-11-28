/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:40:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/28 14:19:35 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Abstract Materia was constructed." << std::endl;
}

AMateria::AMateria(const AMateria &base) : type_(base.type_)
{
	std::cout << "Abstract Materia was copied." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Abstract Materia was destructed" << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type)
{
	std::cout << "Abstract Materia from the type " << this->getType();
	std::cout << " was constructed." << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->type_);
}

AMateria &AMateria::operator=(const AMateria &base)
{
	if (this != &base)
	{
		this->type_ = base.type_;
		std::cout << "Abstract Materia copied through assignment" << std::endl;
	}
	return (*this);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "*ABSTRACT MATERIA POINTING TO " << target.getName() << " *" << std::endl;
}
