/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:58:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/18 18:01:39 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	system("clear");
	std::cout << "\033[93mGood bye! \033[0m" << std::endl;
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
	static int	i;
	if (i == 8)
	{
		i = 0;
	}
	if (i <= 7)
	{
		if (attribute_no == 1)
			list[i].set_firstname(_input);
		else if (attribute_no == 2)
			list[i].set_lastname(_input);
		else if (attribute_no == 3)
			list[i].set_nickname(_input);
		else if (attribute_no == 4)
			list[i].set_pnumber(_input);
		else if (attribute_no == 5)
		{
			list[i].set_secret(_input);
			list[i].exists = true;
			i++;
		}
	}
	else
		i++;
}

void	PhoneBook::add_func(void)
{
	std::string _input;
	
	system("clear");
	std::cout << "\033[37mFirst Name: \033[0m";
	std::getline(std::cin, _input);
	parser(_input, 1, list);
	std::cout << "\033[37mLast Name: \033[0m";
	std::getline(std::cin, _input);
	parser(_input, 2, list);
	std::cout << "\033[37mNickname: \033[0m";
	std::getline(std::cin, _input);
	parser(_input, 3, list);
	std::cout << "\033[37mPhone Number: \033[0m";
	std::getline(std::cin, _input);
	parser(_input, 4, list);
	std::cout << "\033[37mDarkest secret: \033[0m";
	std::getline(std::cin, _input);
	parser(_input, 5, list);
	system("clear");
	std::cout << "\033[92mContact successfully added!\033[0m" << std::endl;
}

void	PhoneBook::startup_func(std::string user)
{
	std::cout << ".----------------------------------." << std::endl;
	std::cout << "| \033[93mAuto-Login: \033[92m" << user << "\033[0m             |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "|        ___   ______      ____    |" << std::endl;
	std::cout << "| Enter |\033[5;37mADD\033[0m| |\033[5;37mSEARCH\033[0m| or |\033[5;37mEXIT\033[0m|:  |" << std::endl;
	std::cout << "|       '---' '------'    '----'   |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "|                                  |" << std::endl;
	std::cout << "'----------------------------------'" << std::endl;
}

void	PhoneBook::displayindex_func(void)
{
	std::cout << ".-------------------------------------------." << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (list[i].exists == true)
		{
			std::cout << "|" << std::right << std::setw(10) << i + 1;
			std::cout << "|" << std::right << std::setw(10) << truncate(list[i].getfirstname()) << "|";
			std::cout << std::right << std::setw(10) << truncate(list[i].getlastname()) << "|";
			std::cout << std::right << std::setw(10) << truncate(list[i].getnickname()) << "|" << std::endl;
			std::cout << "|          |          |          |          |" << std::endl;
		}
	}
	std::cout << ".-------------------------------------------." << std::endl;
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
		std::cout << "\n\033[5;37mType 0 to go back\033[0m" << std::endl;
		std::cout << "> " << std::flush;
		std::getline(std::cin, index);
		if (std::cin.eof())
			return ;
		if (index.length() == 1 && isdigit(index[0]))
		{
			if (index[0] == '0')
				return ;
			i = atoi(&index[0]) - 1;
			if (i >= 0 && i <= 7)
			{
				system("clear");
				std::cout << (i + 1) << "." << std::endl;
				std::cout << "First name: " << list[i].getfirstname() << std::endl;
				std::cout << "Last name: " << list[i].getlastname() << std::endl;
				std::cout << "Nickname: " << list[i].getnickname() << std::endl;
				std::cout << "Phone number: " << list[i].getphonenum() << std::endl;
				std::cout << "Darkest Secret: " << list[i].getsecret() << std::endl;
				std::cout << "\n\033[5;37mType 0 to go back\033[0m" << std::endl;
				std::cout << "> " << std::flush;
				index.clear();
				while (1)
				{
					std::getline(std::cin, index);
					if (std::cin.eof())
						return ;
					if (index.length() == 1 && index[0] == '0')
					{
						system("clear");
						PhoneBook::displayindex_func();
						break ;
					}
				}
			}
		}
		index.clear();
	}
}
