/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:02:41 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/24 15:35:13 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Default Character Constructor" << std::endl;
}

Character::Character(std::string name) : name_(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Character name Constructor" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << "Default Character destructor" << std::endl;
}

Character::Character(Character const &base) : name_(base.getName())
{
	for (int i = 0; i < 4; i++)
	{
		if (base.inventory[i])
			this->inventory[i] = base.inventory[i]->clone();	
	}
}

Character &Character::operator=(Character const &base)
{
	if (this != &base)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (base.inventory[i])
				this->inventory[i] = base.inventory[i]->clone();
			std::cout << "Character copy constructor" << std::endl;
		}
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->name_);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;
	if (!m)
		std::cout << "no materia to equip" << std::endl;

	while (i < 4 && this->inventory[i])
		i++;
	if (i >= 4)
	{
		std::cout << this->name_ << " can't equip more materia" << std::endl;
		return ;
	}
	this->inventory[i] = m;
	std::cout << this->name_ << " has equipped " << m->getType() << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx > 3  || idx < 0)
	{
		std::cout << "Choose a valid slot to unequip" << std::endl;
		return ;
	}
	else if (this->inventory[idx])
	{
		AMateria *lostMateria = this->inventory[idx];
		std::cout << this->name_ << " unequipped " << lostMateria->getType() << std::endl;
		this->inventory[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Invalid Materia slot" << std::endl;
		return ;
	}
	if (!this->inventory[idx])
	{
		std::cout << "There is no materia in slot " << idx + 1 << std::endl;
		return ;
	}
	this->inventory[idx]->use(target);
}

AMateria	*Character::getInventoryMateria(int idx)
{
	return (this->inventory[idx]);
}
