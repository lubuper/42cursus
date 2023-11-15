/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:13:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/15 19:22:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource created" << std::endl;
	return ;	
}

MateriaSource::~MateriaSource()
{
	return ;	
}

MateriaSource::MateriaSource(const MateriaSource &base)
{
	return ;	
}

MateriaSource &MateriaSource::operator=(const MateriaSource &base)
{
	return ;	
}

void	MateriaSource::learnMateria(AMateria*)
{
	return ;	
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	return ;	
}
