/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:26:55 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/02 19:11:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl says:" << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << "Harl goes away." << std::endl;
	return ;
}

void	Harl::debug( void )
{
	std::cout << "this DEBUG!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "this INFO good!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "Harl WARN you now!" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "big ERROR mistake!" << std::endl;
}

void	Harl::complain( std::string level )
{
	void(Harl::*msg_levels[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	message_types[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (message_types[i] == level)
			(this->*msg_levels[i])();
	}
}
