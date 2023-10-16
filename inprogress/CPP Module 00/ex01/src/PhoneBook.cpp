/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/16 08:39:46 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Good bye!" << std::endl;
	return;
}

void	PhoneBook::startup_func(void)
{
	std::cout << ".----------------------------------." << std::endl;
	std::cout << "|        ___   ______      ____    |" << std::endl;
	std::cout << "| Enter |ADD| |SEARCH| or |EXIT|:  |" << std::endl;
	std::cout << "|       '---' '------'    '----'   |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "'----------------------------------'" << std::endl;
}

void	PhoneBook::displayindex_func(void)
{
	std::cout << ".-------------------------------------------." << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << ".-------------------------------------------." << std::endl;
}

void	PhoneBook::search_func(void)
{
	std::string		index;

	PhoneBook::displayindex_func();
	std::cout << "Type the index you want to see" << std::endl;
	std::cout << "Type 0 to go back" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::cin.clear();
		std::cin >> index;
		if (index == "9" || index == "0") //verificar o index
		{
			std::cout << "Good job!" << std::endl;
			break ;
		}
 		else if (index == '0')
		{
			std::cout << "Returning..." << std::endl;
			return ;
		}
		else
		{
			std::cout << "Please specify a valid INDEX" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
}
