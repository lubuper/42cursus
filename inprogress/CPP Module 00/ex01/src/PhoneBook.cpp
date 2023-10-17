/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/17 16:56:10 by lde-sous         ###   ########.fr       */
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

std::string PhoneBook::truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
	else
		return (str);
}

void	PhoneBook::parser(std::string _input, int attribute_no, Contact *list)
{
	static int	i = 0;
	if (i >= 8)
	{
		i = 0;
		list[i].exists = false;
	}
	if (list[i].exists == false && i <= 7)
	{
		if (attribute_no == 1)
			list[i].firstname = _input;
		else if (attribute_no == 2)
			list[i].lastname = _input;
		else if (attribute_no == 3)
			list[i].nickname = _input;
		else if (attribute_no == 4)
			list[i].phonenumber = _input;
		else if (attribute_no == 5)
		{
			list[i].darkest_secret = _input;
			list[i].exists = true;
		}
	}
	else
		i++;
}

void	PhoneBook::add_func(void)
{
	std::string _input;
	
	system("clear");
	std::cout << "First Name: ";
	std::cin >> _input;
	while (_input.size() < 10)
		_input.append(" ");
	std::cout << std::endl;
	parser(_input, 1, list);
	std::cout << "Last Name: ";
	std::cin >> _input;
	while (_input.size() < 10)
		_input.append(" ");
	std::cout << std::endl;
	parser(_input, 2, list);
	std::cout << "Nickname: ";
	std::cin >> _input;
	while (_input.size() < 10)
		_input.append(" ");
	std::cout << std::endl;
	parser(_input, 3, list);
	std::cout << "Phone Number: ";
	std::cin >> _input;
	std::cout << std::endl;
	parser(_input, 4, list);
	std::cout << "darkest secret: ";
	std::cin >> _input;
	std::cout << std::endl;
	parser(_input, 5, list);
	std::cout << "Contact successfully added" << std::endl;
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
/* 	std::cout << 0 << std::endl;
	std::cout << truncate(list[0].firstname) << std::endl;
	std::cout << truncate(list[0].lastname) << std::endl;
	std::cout << truncate(list[0].nickname) << std::endl; */
}

void	PhoneBook::search_func(void)
{
	std::string	index;
	int			i;

	system("clear");
	PhoneBook::displayindex_func();
	while (1)
	{
		std::cout << "Please specify a valid INDEX" << std::endl;
		std::cout << "Type 0 to go back" << std::endl;
		std::cout << "> " << std::flush;
		std::cin.clear();
		std::cin >> index;
		if (index.length() == 1 && isdigit(index[0]))
		{
			if (index[0] == '0')
				return ;
			i = atoi(&index[0]) - 1;
			if (i >= 0 && i <= 7)
			{
				system("clear");
				std::cout << i << std::endl;
				std::cout << list[i].firstname << std::endl;
				std::cout << list[i].lastname << std::endl;
				std::cout << list[i].nickname << std::endl;
				std::cout << list[i].phonenumber << std::endl;
				std::cout << list[i].darkest_secret << std::endl;
				std::cout << "Type 0 to go back" << std::endl;
				std::cout << "> " << std::flush;
				std::cin.clear();
				while (1)
				{
					std::cin >> index;
					if (index.length() == 1 && index[0] == '0')
					{
						system("clear");
						PhoneBook::displayindex_func();
						break ;
					}
				}
			}
		}
		std::cin.clear();
		std::cin.ignore();
	}
}
