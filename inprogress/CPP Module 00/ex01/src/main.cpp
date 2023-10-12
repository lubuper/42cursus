/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/12 19:44:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.hpp"

void	add_func(void)
{
	std::cout << "Contact added!" << std::endl;
}

void	search_func(void)
{
	int	index;
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
	std::cout << "> ";
	std::cin >> index;
	if (index < 9 && index > 0)
		std::cout << "Good job!" << std::endl;
	else
	{
		search_func();
		std::cin >> index;
	}
}

int	main(void)
{
	PhoneBook	pbook;
	std::string option;
	std::cout << ".----------------------------------." << std::endl;
	std::cout << "|        ___   ______      ____    |" << std::endl;
	std::cout << "| Enter |ADD| |SEARCH| or |EXIT|:  |" << std::endl;
	std::cout << "|       '---' '------'    '----'   |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "'----------------------------------'" << std::endl;
	std::cout << "> ";
	std::cin >> option;
	if (option == "ADD")
		add_func();
	if (option == "SEARCH")
		search_func();
	if (option == "EXIT")
		return (std::cout << "Good bye!" << std::endl, 0);
	else if (option != "ADD" && option != "SEARCH" && option != "EXIT")
		std::cout << "Invalid option" << std::endl;
	main();
}
