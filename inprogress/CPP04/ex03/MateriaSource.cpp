/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:13:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/22 11:09:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "MateriaSource constructor" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &base)
{
		for (int i = 0; i < 4; i++)
		{
			if (base.inventory[i])
				this->inventory[i] = base.inventory[i]->clone();
		}
	std::cout << "MS copy constructed" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &base)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (base.inventory[i])
			this->inventory[i] = base.inventory[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;
	while (this->inventory[i] && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Inventory is full" << std::endl;
		return ;
	}
	this->inventory[i] = m;
	std::cout << m->getType() << " has been learned" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;
	while (i < 4 && this->inventory[i] && this->inventory[i]->getType() != type)
		i++;
	if (i >= 4 || !this->inventory[i])
	{
		std::cout << "invalid materia" << std::endl;
		return (NULL);
	}
	std::cout << type << " materia created!" << std::endl;
	return (this->inventory[i]->clone());
}
