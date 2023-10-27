/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:57 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/27 14:11:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string wtype) : type(wtype)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

const std::string&	Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string wtype)
{
	this->type = wtype;
	return ;
}
