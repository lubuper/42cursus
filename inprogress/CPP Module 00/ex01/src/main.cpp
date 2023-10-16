/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/16 20:06:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

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
			pbook.add_func();
			pbook.startup_func();
		}
		if (option == "SEARCH")
		{
			pbook.search_func();
			system("clear");
			std::cout << "Returning..." << std::endl;
			pbook.startup_func();
		}
		else if (option != "ADD" && option != "SEARCH" && option != "EXIT")
			std::cin.ignore();
	}
	return (0);
}
