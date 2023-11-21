/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:02:41 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/17 17:13:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("")
{
	std::cout << "Default Character Constructor"
}

Character::Character(std::string name)
{
	
}

Character::~Character()
{
	
}

Character::Character(Character const &base)
{
	
}

Character &Character::operator=(Character const &base)
{
	
}

std::string const	&Character::getName() const
{
	
}

void	Character::equip(AMateria* m)
{
	
}

void	Character::unequip(int idx)
{
	
}

void	Character::use(int idx, ICharacter& target)
{
	
}

AMateria	*Character::getInventoryMateria(int idx)
{
	
}
