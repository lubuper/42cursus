/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:40:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 17:57:01 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Abstract Materia was constructed." << std::endl;
	return ;
}

AMateria::AMateria(const AMateria &base) : _type(base._type)
{
	std::cout << "Abstract Materia was copied." << std::endl;
	return ;
}

AMateria::~AMateria()
{
	std::cout << "Abstract Materia was destructed" << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Abstract Materia from the type " << this->getType();
	std::cout << " was constructed." << std::endl;
	return ;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "*ABSTRACT MATERIA POINTING TO " << target.getName() << " *" << std::endl;
	return ;
}
