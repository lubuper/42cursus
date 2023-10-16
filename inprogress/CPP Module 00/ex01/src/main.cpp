/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/14 01:07:31 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

void	add_func(void)
{
	std::string _input;
	std::cout << "First Name: ";
	std::cin >> _input;
	std::cout << std::endl;
	std::cout << "Last Name: ";
	std::cin >> _input;
	std::cout << std::endl;
	std::cout << "Nickname: ";
	std::cin >> _input;
	std::cout << std::endl;
	std::cout << "Phone Number: ";
	std::cin >> _input;
	std::cout << std::endl;
	std::cout << "darkest secret: ";
	std::cin >> _input;
	std::cout << std::endl;
	std::cout << "Contact successfully added" << std::endl;
}

int	main(void)
{
	PhoneBook	pbook;
	Contact		list;
	std::string option;

	pbook.startup_func();
	while (option != "EXIT")
	{
		std::cout << "> ";
		std::cin.clear();
		std::cin >> option;
		if (option == "ADD")
		{
			add_func();
			pbook.startup_func();
		}
		if (option == "SEARCH")
		{
			pbook.search_func();
			pbook.startup_func();
		}
		else if (option != "ADD" && option != "SEARCH" && option != "EXIT")
			std::cin.ignore();
	}
	return (0);
}
