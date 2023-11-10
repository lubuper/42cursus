/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:12:04 by lde-sous          #+#    #+#             */
/*   Updated: 2023/11/10 16:47:12 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
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

void	Harl::filter(std::string av)
{
	int i = 0;
	std::string	filter[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 5)
	{
		if (i == 4)
			break ;
		if (av == filter[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
		{
			std::cout << "[ DEBUG ]" << std::endl;
			this->complain("debug");
			std::cout << "[ INFO ]" << std::endl;
			this->complain("info");
			std::cout << "[ WARNING ]" << std::endl;
			this->complain("warning");
			std::cout << "[ ERROR ]" << std::endl;
			this->complain("error");
			break ;
		}
		case 1:
		{	
			std::cout << "[ INFO ]" << std::endl;
			this->complain("info");
			std::cout << "[ WARNING ]" << std::endl;
			this->complain("warning");
			std::cout << "[ ERROR ]" << std::endl;
			this->complain("error");
			break ;
		}
		case 2:
		{
			std::cout << "[ WARNING ]" << std::endl;
			this->complain("warning");
			std::cout << "[ ERROR ]" << std::endl;
			this->complain("error");
			break ;
		}
		case 3:
		{
			std::cout << "[ ERROR ]" << std::endl;
			this->complain("error");
			break ;
		}
		default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
