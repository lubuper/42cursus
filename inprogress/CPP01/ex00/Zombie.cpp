/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:37:34 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/20 19:24:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "It's aliiiiveee!!" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Noooo!! " << this->name << " has re-died!" << std::endl;
	return ;
}

std::string	Zombie::name_getter(void)
{
	return(this->name);
}

std::string	Zombie::name_setter(std::string str)
{
	this->name = str;
	return (this->name);
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
