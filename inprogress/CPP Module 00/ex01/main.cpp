/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/18 17:57:35 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	get_user(char **envp)
{
	std::string user;
	for (int i = 0; envp[i] != NULL; i++)
	{
	    std::string env(envp[i]);
	    if (env.find("USER=") == 0)
	    {
	        user = env.substr(5);
	        break;
	    }
	}
	return (user);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;

	PhoneBook	pbook;
	Contact		list;
	std::string option;
	std::string	user;

	system("clear");
	user = get_user(envp);
	pbook.startup_func(user);
	while (option != "EXIT")
	{
		std::cout << "> " << std::flush;
		std::getline(std::cin, option);
		if (std::cin.eof())
			return(1);
		if (option == "ADD")
		{
			pbook.add_func();
			pbook.startup_func(user);
		}
		else if (option == "SEARCH")
		{
			pbook.search_func();
			system("clear");
			std::cout << " \033[93mReturning... \033[0m" << std::endl;
			pbook.startup_func(user);
		}
		else if (option == "EXIT")
			break ;
		option.clear();
	}
	return (0);
}
