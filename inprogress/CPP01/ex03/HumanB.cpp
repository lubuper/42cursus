/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:42:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/26 20:20:31 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : b_name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack()
{
	std::cout << this->b_name << " attacks with their " << this->b_weapon << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->b_weapon = &weapon;
}
